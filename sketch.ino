/*
  Medidor de Nível da Caixa d'Água – ESP32 + ThingSpeak
  Autor: Julia Lemos Alves da Silva – 2025

  ► Bibliotecas necessárias
    • WiFi.h  (vem com a IDE)
    • ThingSpeak by MathWorks  → instale no Library Manager

*/

#include <WiFi.h>
#include <ThingSpeak.h>

// ---------- Wi‑Fi ----------
const char* WIFI_SSID     = "Wokwi-GUEST";
const char* WIFI_PASSWORD = "";

// ---------- ThingSpeak ----------
unsigned long channelID   = 3002897;           
const char* writeAPIKey   = "M0YRCF0PD9L7Z2N6";

// ---------- Pino do “sensor” ----------
const int SENSOR_PIN = 34; 

// Cliente Wi‑Fi para ThingSpeak
WiFiClient client;

// -----------------------------------------------------------------
//  Conecta (ou reconecta) ao Wi‑Fi
// -----------------------------------------------------------------
void connectWiFi() {
  if (WiFi.status() == WL_CONNECTED) return;

  Serial.print("Conectando ao Wi‑Fi");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  uint8_t tentativas = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (++tentativas > 20) {               // 10 s de tentativa
      Serial.println("\nFalha no Wi‑Fi – reiniciando ESP...");
      ESP.restart();
    }
  }
  Serial.println("\nWi‑Fi OK! IP: " + WiFi.localIP().toString());
}

// -----------------------------------------------------------------
//  Setup
// -----------------------------------------------------------------
void setup() {
  Serial.begin(115200);
  delay(1000);            
  connectWiFi();
  ThingSpeak.begin(client);
}

// -----------------------------------------------------------------
//  Loop principal
// -----------------------------------------------------------------
void loop() {
  // 1) Leitura analógica (0–4095)
  int raw = analogRead(SENSOR_PIN);

  // 2) Converte em porcentagem (0–100)
  float waterPercent = map(raw, 0, 4095, 0, 100);

  // 3) Exibe no Serial
  Serial.printf("Valor bruto: %4d  |  Nível: %2.0f %%\n", raw, waterPercent);

  // 4) Envia ao ThingSpeak
  ThingSpeak.setField(1, waterPercent);
  int httpCode = ThingSpeak.writeFields(channelID, writeAPIKey);

  if (httpCode == 200) {
    Serial.println("✅ Dados enviados com sucesso!");
  } else {
    Serial.printf("⚠️ Falha (HTTP %d)\n", httpCode);
    // -301 → sem Wi‑Fi   | 400/401 → API Key ou campo errado
    if (httpCode < 0) connectWiFi();  // reconecta se perdeu Wi‑Fi
  }

  delay(15000);
}
