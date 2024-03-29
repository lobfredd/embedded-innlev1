#include <Arduino.h>

class MatrixMaster {
  private:
    int dataPin;
    int clockPin;
    int latchPin;
    byte status[8];
    bool commonAnode;
    bool mirror;
    int numOfParents;
    
   public:
    MatrixMaster(int dataPin, int clockPin, int latchPin, bool commonAnode = false, int numOfParents = 0);

    void displayTest(bool on);
    void decodeMode(bool on);
    void setScanLimit(int limit);
    void setBrightness(int brightness);
    void isShutdown(bool status);
    void clear();
    void setMirror(bool on);
    void showBrightnessBar(int brightness);

    void setRow(int row, bool on);
    void setRow(int row, byte data);

    void setColoumn(int col, bool on);
    void setColoumn(int col, byte data);

    void led(int row, int col, bool on);

    void scrollText(String text, int slowdownFactor = 100);
    
    private:
    void writeCommand(byte registerr, byte data);
    void writeRow(int row, byte data);
    void writeCol(int col, byte data);
    byte reverseBitOrder(byte b, int bits = 8);
    void updateStatus(int row, byte data, bool on);
    byte getColData(int col);
    void appendByte(byte *dest, byte src, int bitIndex);
    int getIndexOfAscii(String *text, int index);
    void centerLastChar(byte ch[], int slowdownFactor);
};
