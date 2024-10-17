# README para Conexión del Arduino Pro Micro (ATmega32U4)

## Descripción

Este proyecto utiliza un Arduino Pro Micro para ejecutar comandos en la computadora mediante la biblioteca `Keyboard`. Tiene dos botones que abren Notepad y la Calculadora, y un LED rojo que indica cuando se está ejecutando un comando.

## Conexiones

### Componentes Necesarios
- 1 x Arduino Pro Micro (ATmega32U4)
- 2 x Botones
- 1 x LED rojo
- 1 x Resistencia (220Ω recomendada para el LED)
- Cables de conexión
- Protoboard (opcional)

### Conexiones de Hardware

#### Diagrama de Conexión

```
Arduino Pro Micro
-----------------
   Pin 2 ----> [ Botón 1 ] ----> GND
   Pin 3 ----> [ LED Rojo ] ----> [ Resistencia ] ----> GND
   Pin 8 ----> [ Botón 2 ] ----> GND
```

### Descripción de Conexiones

- **Botón 1:**
  - Conectado desde el **Pin 2** del Arduino a un terminal del botón.
  - El otro terminal del botón se conecta a **GND**.

- **Botón 2:**
  - Conectado desde el **Pin 8** del Arduino a un terminal del segundo botón.
  - El otro terminal del botón se conecta a **GND**.

- **LED Rojo:**
  - Conectado desde el **Pin 3** del Arduino a un terminal del LED (el cátodo, que es el lado más corto).
  - El otro terminal del LED se conecta a una resistencia (220Ω).
  - El otro terminal de la resistencia se conecta a **GND**.


