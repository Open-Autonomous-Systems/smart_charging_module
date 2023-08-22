// Init external flash
flash.begin();

void flash_setup() {
// Open file system on the flash
    if (!fatfs.begin(&flash)) {
        Serial.println("Error: filesystem is not existed. Please try SdFat_format example to make one.");
        while (1) {
            yield();
            delay(1);
        }
    }
    Serial.println("initialization done.");

// open the file. note that only one file can be open at a time,
// so you have to close this one before opening another.
    string fName = "log_"+ ss_.getEpoch();
    myFile = fatfs.open("log.csv", FILE_WRITE);

// if the file opened okay, write to it:
    if (myFile) {
        Serial.print("Writing to test.txt...");
        myFile.println("testing 1, 2, 3.");
// close the file:
        myFile.close();
        Serial.println("done.");
    } else {
// if the file didn't open, print an error:
        Serial.println("error opening test.txt");
    }
}