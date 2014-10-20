

    testacc.ino
    ADXL362.cpp
    ADXL362.h

263
264
265
266
267
268
269
270
271
272
273
274
275
276
277
278
279
280
281
282
283
284
285
286
287
288
289
290
291
292
293
294
295
296
void ADXL362::SPIwriteOneRegister(byte regAddress, byte regValue){
  
    digitalWrite(slaveSelectPin, LOW);
    SPI.transfer(0x0A);  // write instruction
    SPI.transfer(regAddress);
    SPI.transfer(regValue);
    digitalWrite(slaveSelectPin, HIGH);
}
int16_t ADXL362::SPIreadTwoRegisters(byte regAddress){
    int16_t twoRegValue = 0;
  
    digitalWrite(slaveSelectPin, LOW);
    SPI.transfer(0x0B);  // read instruction
    SPI.transfer(regAddress);  
    twoRegValue = SPI.transfer(0x00);
    twoRegValue = twoRegValue + (SPI.transfer(0x00) << 8);
    digitalWrite(slaveSelectPin, HIGH);
    return twoRegValue;
}  
void ADXL362::SPIwriteTwoRegisters(byte regAddress, int16_t twoRegValue){
    byte twoRegValueH = twoRegValue >> 8;
    byte twoRegValueL = twoRegValue;
  
    digitalWrite(slaveSelectPin, LOW);
    SPI.transfer(0x0A);  // write instruction
    SPI.transfer(regAddress);  
    SPI.transfer(twoRegValueL);
    SPI.transfer(twoRegValueH);
    digitalWrite(slaveSelectPin, HIGH);
}
Ready.
