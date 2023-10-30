## Read Data From Register MODBUS RTU TUF2000B

Program berikut berfungsi untuk membaca data melalui protocol MODBUS RTU dari alat UFM(Ultrasonic Flow Meter) dengan seri TUF2000B. Menggunakan ESP8266 sebagai microcontroller dengan komunikasi Serial/UART.

**Data yang dibaca:**

- [x] Flow rate `m3/h`
- [x] Flow Today `m3`
- [x] Flow Month `m3`
- [x] Velocity `m/s`

- Sebenarnya untuk data yang diinginkan bebas sesuai dengan parameter yang ada di datasheet, namun disini saya hanya memberi contoh empat data saja. Jika anda menginginkan data yang berbeda silahkan ubah register pada syntax berikut:

```cpp
result = sensor.readHoldingRegisters(0x0001, 2);
```

- Ubah angka `0x0001` sesuai dengan register data yang ingin didapat/dibaca dengan format `hex`

- Library yang digunakan adalah `ModbusMaster` yang bisa anda unduh [disini](https://github.com/4-20ma/ModbusMaster)

- Untuk komunikasi serialnya saya menggunakan library `SofwareSerial`. Sesuaikan pin yang digunakan

```cpp
#define RX_PIN 14 // D6
#define TX_PIN 12 // D5
```

- Anda dapat membaca data register MODBUS RTU TUF2000B [disini](https://blog.veto.cl/com_virtuemart/files/manuales/otros_documentos/N0646058_modbus_formato_datos.pdf)

---
