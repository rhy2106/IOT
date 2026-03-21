# IOT

## Descrição
Repositorio para guardar e anotar como utilizar um arduino

## Como Listar o Arduino Conectado no seu computador:
```
arduino-cli board list

```
## Como Compilar mandar o codigo para o arduino
```
arduino-cli compile --fqbn arduino:avr:uno servomotor
arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:uno servomotor
```

## Como Listar e Baixar Bibliotecas
```
arduino-cli lib list
arduino-cli lib update-index
arduino-cli lib search "Nome da Biblioteca"
arduino-cli lib install "Nome da Biblioteca"
```

