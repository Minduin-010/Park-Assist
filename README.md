# Park-Assist
## 🧠 Funcionamento do Sistema

1. **Leitura de distância (HC-SR04)**  
   Mede a distância até o veículo usando `pulseIn()` e converte o tempo em centímetros.

2. **Controle da Cancela**  
   - Se o carro estiver a menos de 50 cm → cancela abre (servo 90°).  
   - Após 3 segundos → cancela fecha (servo 0°).  
   - Controle feito com `millis()` (sem `delay()`).

3. **Sistema de Alerta de Proximidade**  
   - Distância < 20 cm → LED e buzzer piscam a cada 200 ms.  
   - Distância < 10 cm → piscam a cada 50 ms (alerta crítico).  

4. **Contagem de Vagas**  
   - Ao detectar carro na entrada → `vagasDisponiveis--`.  
   - Ao detectar carro na saída → `vagasDisponiveis++`.  
   - Valor exibido no **LCD I2C**, atualizado a cada 500 ms.  

---

## 🧩 Estrutura do Código
- Uso de **função de medição** (`medirDistancia`) para o sensor.  
- **Controle não bloqueante** com `millis()` para múltiplas tarefas.  
- Atualização independente da cancela, alerta e display.  

---

Integrantes:
Icaro de Oliveira
