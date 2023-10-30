##Read Data From Register MODBUS RTU TUF2000B

Program berikut berfungsi untuk membaca data melalui protocol MODBUS RTU dari alat UFM(Ultrasonic Flow Meter) dengan seri TUF2000B. Menggunakan ESP8266 sebagai microcontroller dengan komunikasi Serial/UART.

**Data yang didapat:**

- [x] Flow rate `m3/h`
- [x] Flow Today `m3`
- [x] Flow Month `m3`
- [x] Velocity `l/s`

Sebenarnya untuk data yang diinginkan bebas sesuai dengan parameter yang ada sesuai datasheet, namun disini saya hanya memberi contoh empat data saja. Jika anda menginginkan data yang berbeda silahkan ubah register pada syntax berikut:

```cpp
result = sensor.readHoldingRegisters(0x0001, 2);
```

ubah angka `0x0001` sesuai dengan register data yang ingin didapat/dibaca dengan format `hex`
