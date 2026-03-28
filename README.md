# IOT

## Descrição
Repositorio para guardar e anotar como utilizar um arduino

## Como Listar o Arduino Conectado no seu computador:
```
arduino-cli board list

```
## Como Compilar mandar o codigo para o arduino
O makefile está programado para apenas realizar ações com o ultimo codigo modificado.
- Para ver as configurações de como o codigo será compilado:
```
make
```
- Para compilar o ultimo codigo modificado:
```
make compile
```
-  Para mandar o codigo para o arduino:
```
make upload
```

## Como Listar e Baixar Bibliotecas
```
arduino-cli lib list
arduino-cli lib update-index
arduino-cli lib search "Nome da Biblioteca"
arduino-cli lib install "Nome da Biblioteca"
```

