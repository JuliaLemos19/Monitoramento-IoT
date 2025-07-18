# 💧 Monitoramento IoT do Nível da Caixa d’Água com ESP32 e ThingSpeak

## 📌 Descrição do Projeto

Este projeto tem como objetivo monitorar, de forma remota, o nível de água de uma caixa d'água residencial utilizando um microcontrolador ESP32 e um sensor de nível (simulado por um potenciômetro) em ambiente virtual Wokwi. Os dados são enviados periodicamente para a nuvem através da plataforma ThingSpeak, onde são visualizados em tempo real em forma de gráficos.

---

## 🧠 Contextualização do Problema

Em muitas residências, o controle do nível da caixa d’água é feito manualmente, o que pode causar transbordamentos ou falta d’água, especialmente em horários de maior consumo. A ausência de monitoramento automatizado contribui para o desperdício de água e energia elétrica, já que bombas d’água podem ser ligadas desnecessariamente.

Dessa forma, o uso de um sistema IoT para acompanhar o nível da água em tempo real permite uma gestão mais eficiente e sustentável do recurso hídrico, evitando desperdícios, otimizando o uso da bomba d’água e aumentando o conforto do morador.

---

## ⚙️ Tecnologias Utilizadas

- [Wokwi](https://wokwi.com/) — Simulador de circuitos e microcontroladores
- ESP32 — Microcontrolador com Wi-Fi integrado
- Potenciômetro — Simulação de sensor de nível
- Biblioteca `ThingSpeak.h` — Envio de dados para a nuvem
- ThingSpeak — Visualização online de dados em tempo real
- GitHub — Versionamento e documentação

---

## 🔁 Funcionamento do Sistema

1. O ESP32 lê continuamente o valor do potenciômetro (0–4095).
2. O valor é convertido para uma porcentagem (0%–100%) representando o nível da caixa d'água.
3. A cada 15 segundos, esse valor é enviado para a nuvem usando a API do ThingSpeak.
4. O gráfico no canal público do ThingSpeak mostra a evolução do nível da caixa d’água em tempo real.
5. As mensagens no terminal indicam o status da leitura e do envio dos dados.

---

## 🖥️ Capturas de Tela

| Simulação no Wokwi | Gráfico no ThingSpeak |
|--------------------|------------------------|
| ![Simulação Wokwi](FT01.png) | ![Gráfico ThingSpeak](FT02.png) |

---

## 🧪 Como Replicar o Projeto

### 1. Simule no Wokwi:
🔗 [Abrir projeto Wokwi](https://wokwi.com/projects/435476093261588481)

### 2. Visualize os dados:
🔗 [Canal público no ThingSpeak](https://thingspeak.com/channels/3002897)

### 3. Requisitos:
- Conta gratuita no ThingSpeak
- Biblioteca `ThingSpeak.h` instalada
- Conexão Wi-Fi válida (no Wokwi, pode deixar `"Wokwi-GUEST"`)

## 📽️ Vídeo de Apresentação

🎬 [Assista no YouTube](https://youtu.be/ssgjcu73n8o)

---

## 🙋 Sobre o Autor

Projeto desenvolvido por **Julia Lemos Alves da Silva** para a disciplina de **Introdução à Automação de Ambientes e Processos**, com foco em aplicações reais de IoT.

---

## 📄 Licença

Este projeto é de uso acadêmico e educacional.

