
#ifndef PT6312_H
#define PT6312_H

// Select one of the testboards for Princeton PT6312 VFD controller
#include "PT6312_Config.h"



//PT6312 Display and Keymatrix data
#define PT6312_MAX_NR_GRIDS   11
#define PT6312_BYTES_PER_GRID  2
//Significant bits Keymatrix data
#define PT6312_KEY_MSK      0xFF 

//Memory size in bytes for Display and Keymatrix
#define PT6312_DISPLAY_MEM  (PT6312_MAX_NR_GRIDS * PT6312_BYTES_PER_GRID)
#define PT6312_KEY_MEM         3


//Reserved bits for commands
#define PT6312_CMD_MSK      0xE0

//Mode setting command
#define PT6312_MODE_SET_CMD 0x00
#define PT6312_GR4_SEG16    0x00
#define PT6312_GR5_SEG16    0x01
#define PT6312_GR6_SEG16    0x02
#define PT6312_GR7_SEG15    0x03 //default
#define PT6312_GR8_SEG14    0x04
#define PT6312_GR9_SEG13    0x05
#define PT6312_GR10_SEG12   0x06
#define PT6312_GR11_SEG11   0x07


//Data setting commands
#define PT6312_DATA_SET_CMD 0x40
#define PT6312_DATA_WR      0x00
#define PT6312_LED_WR       0x01
#define PT6312_KEY_RD       0x02
#define PT6312_SW_RD        0x03
#define PT6312_ADDR_INC     0x00
#define PT6312_ADDR_FIXED   0x04
#define PT6312_MODE_NORM    0x00
#define PT6312_MODE_TEST    0x08

//LED settings data
#define PT6312_LED_MSK      0x0F
#define PT6312_LED1         0x01
#define PT6312_LED2         0x02
#define PT6312_LED3         0x04
#define PT6312_LED4         0x08

//Switch settings data
#define PT6312_SW_MSK       0x0F
#define PT6312_SW1          0x01
#define PT6312_SW2          0x02
#define PT6312_SW3          0x04
#define PT6312_SW4          0x08

//Address setting commands
#define PT6312_ADDR_SET_CMD 0xC0
#define PT6312_ADDR_MSK     0x1F

//Display control commands
#define PT6312_DSP_CTRL_CMD 0x80
#define PT6312_BRT_MSK      0x07
#define PT6312_BRT0         0x00 //Pulsewidth 1/16
#define PT6312_BRT1         0x01
#define PT6312_BRT2         0x02
#define PT6312_BRT3         0x03
#define PT6312_BRT4         0x04
#define PT6312_BRT5         0x05
#define PT6312_BRT6         0x06
#define PT6312_BRT7         0x07 //Pulsewidth 14/16

#define PT6312_BRT_DEF      PT6312_BRT3

#define PT6312_DSP_OFF      0x00
#define PT6312_DSP_ON       0x08


/** A class for driving Princeton PT6312 VFD controller
 *
 * @brief Supports 4 Grids of 16 Segments upto 11 Grids of 11 Segments. Also supports a scanned keyboard of upto 24 keys, 4 switches and 4 LEDs.
 *        SPI bus interface device. 
 */
class PT6312 {
 public:

  /** Enums for display mode */
  enum Mode {
    Grid4_Seg16  = PT6312_GR4_SEG16,
    Grid5_Seg16  = PT6312_GR5_SEG16,
    Grid6_Seg16  = PT6312_GR6_SEG16,
    Grid7_Seg15  = PT6312_GR7_SEG15,
    Grid8_Seg14  = PT6312_GR8_SEG14,
    Grid9_Seg13  = PT6312_GR9_SEG13,
    Grid10_Seg12 = PT6312_GR10_SEG12,
    Grid11_Seg11 = PT6312_GR11_SEG11   
  };
  
  /** Datatypes for display and keymatrix data */
  typedef char DisplayData_t[PT6312_DISPLAY_MEM];
  typedef char KeyData_t[PT6312_KEY_MEM];
    
 /** Constructor for class for driving Princeton PT6312 VFD controller
  *
  * @brief Supports 4 Grids of 16 Segments upto 11 Grids of 11 Segments. Also supports a scanned keyboard of upto 24 keys, 4 switches and 4 LEDs.
  *        SPI bus interface device.   
  *  @param  PinName mosi, miso, sclk, cs SPI bus pins
  *  @param  Mode selects either number of Grids and Segments (default 7 Grids, 15 Segments)
  */
  PT6312(PinName mosi, PinName miso, PinName sclk, PinName cs, Mode mode=Grid7_Seg15);
      
  /** Clear the screen and locate to 0
   */ 
  void cls();  

  /** Write databyte to PT6312
   *  @param  int address display memory location to write byte
   *  @param  char data byte written at given address
   *  @return none
   */ 
  void writeData(int address, char data); 
 
  /** Write Display datablock to PT6312
   *  @param  DisplayData_t data Array of PT6312_DISPLAY_MEM (=22) bytes for displaydata (starting at address 0)
   *  @param  length number bytes to write (valid range 0..PT6312_DISPLAY_MEM (=22), starting at address 0)   
   *  @return none
   */   
  void writeData(DisplayData_t data, int length = PT6312_DISPLAY_MEM);


  /** Read keydata block from PT6312
   *  @param  *keydata Ptr to Array of PT6312_KEY_MEM (=3) bytes for keydata
   *  @return bool keypress True when at least one key was pressed
   *
   * Note: Due to the hardware configuration the PT6312 key matrix scanner will detect multiple keys pressed at same time,
   *       but this may result in some spurious keys also being set in keypress data array.
   *       It may be best to ignore all keys in those situations. That option is implemented in this method depending on #define setting.
   */   
  bool getKeys(KeyData_t *keydata);


  /** Read switches from PT6312
   *
   *  @param  none
   *  @return char for switch data (4 least significant bits)
   *
   */   
  char getSwitches();

  /** Set LEDs
    *
    * @param  char leds (4 least significant bits)  
    * @return none
    */
  void setLED (char leds = 0);

  /** Set Brightness
    *
    * @param  char brightness (3 significant bits, valid range 0..7 (1/16 .. 14/14 dutycycle)  
    * @return none
    */
  void setBrightness(char brightness = PT6312_BRT_DEF);
  
  /** Set the Display mode On/off
    *
    * @param bool display mode
    */
  void setDisplay(bool on);
  
 private:  
  SPI _spi;
  DigitalOut _cs;
  Mode _mode;
  char _display;
  char _bright; 
  
  /** Init the SPI interface and the controller
    * @param  none
    * @return none
    */ 
  void _init();

  /** Helper to reverse all command or databits. The PT6312 expects LSB first, whereas SPI is MSB first
    *  @param  char data
    *  @return bitreversed data
    */ 
  char _flip(char data);

  /** Write command and parameter to PT6312
    *  @param  int cmd Command byte
    *  &Param  int data Parameters for command
    *  @return none
    */ 
  void _writeCmd(int cmd, int data);  
};



#if (DVP630_TEST == 1)
// Derived class for PT6312 used in Philips DVP630 front display unit
//
#include "Font_16Seg.h"

#define DVP630_NR_GRIDS  7
#define DVP630_NR_DIGITS 7
#define DVP630_DIG1_IDX  1
#define DVP630_NR_UDC    8

/** Constructor for class for driving Princeton PT6312 VFD controller as used in Philips DVP630
  *
  *  @brief Supports 7 Digits of 15 Segments. Also supports a scanned keyboard of 3 keys, 3 switches and 1 LED.
  *  
  *  @param  PinName mosi, miso, sclk, cs SPI bus pins
  */
class PT6312_DVP630 : public PT6312, public Stream {
 public:

  /** Enums for Icons */
  //  Grid encoded in 8 MSBs, Icon pattern encoded in 24 LSBs
  enum Icon {
    COL3  = (5<<24) | S_COL3,
    COL5  = (3<<24) | S_COL5
  };
  
  typedef char UDCData_t[DVP630_NR_UDC][2];
  
 /** Constructor for class for driving Princeton PT6312 VFD controller as used in Philips DVP630
   *
   * @brief Supports 7 Digits of 15 Segments. Also supports a scanned keyboard of 3 keys, 3 switches and 1 LED.
   *  
   * @param  PinName mosi, miso, sclk, cs SPI bus pins
   */
  PT6312_DVP630(PinName mosi, PinName miso, PinName sclk, PinName cs);

#if DOXYGEN_ONLY
    /** Write a character to the Display
     *
     * @param c The character to write to the display
     */
    int putc(int c);

    /** Write a formatted string to the Display
     *
     * @param format A printf-style format string, followed by the
     *               variables to use in formatting the string.
     */
    int printf(const char* format, ...);   
#endif

     /** Locate cursor to a screen column
     *
     * @param column  The horizontal position from the left, indexed from 0
     */
    void locate(int column);
    
    /** Clear the screen and locate to 0
     * @param bool clrAll Clear Icons also (default = false)
     */
    void cls(bool clrAll = false);

    /** Set Icon
     *
     * @param Icon icon Enums Icon has Digit position encoded in 8 MSBs, Icon pattern encoded in 16 LSBs
     * @return none
     */
    void setIcon(Icon icon);

    /** Clr Icon
     *
     * @param Icon icon Enums Icon has Digit position encoded in 8 MSBs, Icon pattern encoded in 16 LSBs
     * @return none
     */
    void clrIcon(Icon icon);

   /** Set User Defined Characters (UDC)
     *
     * @param unsigned char udc_idx   The Index of the UDC (0..7)
     * @param int udc_data            The bitpattern for the UDC (16 bits)       
     */
    void setUDC(unsigned char udc_idx, int udc_data);


   /** Number of screen columns
    *
    * @param none
    * @return columns
    */
    int columns();   
 
   /** Write databyte to PT6312
     *  @param  int address display memory location to write byte
     *  @param  char data byte written at given address
     *  @return none
     */ 
    void writeData(int address, char data){
      PT6312::writeData(address, data);
    }        
 
   /** Write Display datablock to PT6312
    *  @param  DisplayData_t data Array of PT6312_DISPLAY_MEM (=22) bytes for displaydata (starting at address 0)
    *  @param  length number bytes to write (valid range 0..(DVP630_NR_GRIDS*2) (=14), starting at address 0)   
    *  @return none
    */   
    void writeData(DisplayData_t data, int length = (DVP630_NR_GRIDS*2)) {
      PT6312::writeData(data, length);
    }  

protected:  
    // Stream implementation functions
    virtual int _putc(int value);
    virtual int _getc();

private:
    int _column;                     // Current cursor location
    int _columns;                    // Max number of columns
    
    DisplayData_t _displaybuffer;    // Local mirror for all chars and icons
    UDCData_t _UDC_16S;              // User Defined Character pattterns (UDC)
};
#endif

#if (DVD462_TEST == 1)
// Derived class for DVD462 in Cyberhome DVD462 front display unit
//   Grids 2-4 each display two 7-Segment digits, Grid 5 displays one 7-Segment digit. 
//   Several Icons are also available.
//
#include "Font_7Seg.h"

#define DVD462_NR_GRIDS  6
#define DVD462_NR_DIGITS 7
//#define DVD462_DIG1_IDX  1
#define DVD462_NR_UDC    8

/** Constructor for class for driving Princeton PT6312 VFD controller as used in DVD462
  *
  *  @brief Supports 7 Digits of 7 Segments and icons. Also supports a scanned keyboard of 7 keys and 1 LED.
  *  
  *  @param  PinName mosi, miso, sclk, cs SPI bus pins
  */
class PT6312_DVD462 : public PT6312, public Stream {
 public:

  /** Enums for Icons */
  //  Grid encoded in 8 MSBs, Icon pattern encoded in 24 LSBs
  enum Icon {
    MP3  = (1<<24) | S7_MP3,
    CD   = (1<<24) | S7_CD,
    V    = (1<<24) | S7_V,
    S    = (1<<24) | S7_S,
    DVD  = (1<<24) | S7_DVD,

    DDD  = (2<<24) | S7_DDD,
    DTS  = (2<<24) | S7_DTS,

    COL5 = (3<<24) | S7_COL5,

    COL3 = (4<<24) | S7_COL3,    

    ARW  = (5<<24) | S7_ARW,
    ALL  = (5<<24) | S7_ALL,
    PSE  = (5<<24) | S7_PSE,
    PLY  = (5<<24) | S7_PLY,
    PBC  = (5<<24) | S7_PBC,
    
    P1   = (6<<24) | S7_P1,
    P2   = (6<<24) | S7_P2,    
    P3   = (6<<24) | S7_P3,    
    P4   = (6<<24) | S7_P4,    
    P5   = (6<<24) | S7_P5,
    P6   = (6<<24) | S7_P6,
    P7   = (6<<24) | S7_P7,
    P8   = (6<<24) | S7_P8,
    P9   = (6<<24) | S7_P9,
    P10  = (6<<24) | S7_P10,
    P11  = (6<<24) | S7_P11,
    P12  = (6<<24) | S7_P12,
    P13  = (6<<24) | S7_P13

  };
  
  typedef char UDCData_t[DVD462_NR_UDC];
  
 /** Constructor for class for driving Princeton PT6312 VFD controller as used in DVD462
   *
   * @brief Supports 7 Digits of 7 Segments and Icons. Also supports a scanned keyboard of 7 keys and 1 LED.
   *  
   * @param  PinName mosi, miso, sclk, cs SPI bus pins
   */
  PT6312_DVD462(PinName mosi, PinName miso, PinName sclk, PinName cs);

#if DOXYGEN_ONLY
    /** Write a character to the Display
     *
     * @param c The character to write to the display
     */
    int putc(int c);

    /** Write a formatted string to the Display
     *
     * @param format A printf-style format string, followed by the
     *               variables to use in formatting the string.
     */
    int printf(const char* format, ...);   
#endif

     /** Locate cursor to a screen column
     *
     * @param column  The horizontal position from the left, indexed from 0
     */
    void locate(int column);
    
    /** Clear the screen and locate to 0
     * @param bool clrAll Clear Icons also (default = false)
     */
    void cls(bool clrAll = false);

    /** Set Icon
     *
     * @param Icon icon Enums Icon has Grid position encoded in 8 MSBs, Icon pattern encoded in 16 LSBs
     * @return none
     */
    void setIcon(Icon icon);

    /** Clr Icon
     *
     * @param Icon icon Enums Icon has Grid position encoded in 8 MSBs, Icon pattern encoded in 16 LSBs
     * @return none
     */
    void clrIcon(Icon icon);

   /** Set User Defined Characters (UDC)
     *
     * @param unsigned char udc_idx   The Index of the UDC (0..7)
     * @param int udc_data            The bitpattern for the UDC (16 bits)       
     */
    void setUDC(unsigned char udc_idx, int udc_data);


   /** Number of screen columns
    *
    * @param none
    * @return columns
    */
    int columns();   

   /** Write databyte to PT6312
     *  @param  int address display memory location to write byte
     *  @param  char data byte written at given address
     *  @return none
     */ 
    void writeData(int address, char data){
      PT6312::writeData(address, data);
    }        
 
   /** Write Display datablock to PT6312
    *  @param  DisplayData_t data Array of PT6312_DISPLAY_MEM (=22) bytes for displaydata (starting at address 0)
    *  @param  length number bytes to write (valid range 0..(DVD462_NR_GRIDS*2) (=14), starting at address 0)   
    *  @return none
    */   
    void writeData(DisplayData_t data, int length = (DVD462_NR_GRIDS*2)) {
      PT6312::writeData(data, length);
    }  

protected:  
    // Stream implementation functions
    virtual int _putc(int value);
    virtual int _getc();

private:
    int _column;                     // Current cursor location
    int _columns;                    // Max number of columns
    
    DisplayData_t _displaybuffer;    // Local mirror for all chars and icons
    UDCData_t _UDC_7S;               // User Defined Character pattterns (UDC)    
};
#endif

#if (C2233_TEST == 1)
// Derived class for C2233 front display unit
//   Grids 2-4 each display two 7-Segment digits, Grid 5 displays one 7-Segment digit. 
//   Several Icons are also available.
//
#include "Font_7Seg.h"

#define C2233_NR_GRIDS  6
#define C2233_NR_DIGITS 7
//#define C2233_DIG1_IDX  1
#define C2233_NR_UDC    8

/** Constructor for class for driving Princeton PT6312 VFD controller as used in C2233
  *
  *  @brief Supports 7 Digits of 7 Segments and icons. Also supports a scanned keyboard of 7 keys.
  *  
  *  @param  PinName mosi, miso, sclk, cs SPI bus pins
  */
class PT6312_C2233 : public PT6312, public Stream {
 public:

  /** Enums for Icons */
  //  Grid encoded in 8 MSBs, Icon pattern encoded in 24 LSBs
  enum Icon {
    MP3  = (2<<24) | S7_MP3,
    PBC  = (2<<24) | S7_PBC,

    COL5 = (3<<24) | S7_COL5,
    CAM  = (3<<24) | S7_CAM,

    COL3 = (4<<24) | S7_COL3,        
    DDD  = (4<<24) | S7_DDD,
    
    ARW  = (5<<24) | S7_ARW,
    ALL  = (5<<24) | S7_ALL,
    PSE  = (5<<24) | S7_PSE,
    PLY  = (5<<24) | S7_PLY,
    CD   = (5<<24) | S7_CD,
    V    = (5<<24) | S7_V,
    S    = (5<<24) | S7_S,
    DTS  = (5<<24) | S7_DTS,
   
    P1   = (6<<24) | S7_P1,
    P2   = (6<<24) | S7_P2,    
    P3   = (6<<24) | S7_P3,    
    P4   = (6<<24) | S7_P4,    
    P5   = (6<<24) | S7_P5,
    P6   = (6<<24) | S7_P6,
    P7   = (6<<24) | S7_P7,
    P8   = (6<<24) | S7_P8,
    P9   = (6<<24) | S7_P9,
    P10  = (6<<24) | S7_P10,
    P11  = (6<<24) | S7_P11,
    P12  = (6<<24) | S7_P12,
    P13  = (6<<24) | S7_P13,

    DVD  = (6<<24) | S7_DVD
  };
  
  typedef char UDCData_t[C2233_NR_UDC];
  
 /** Constructor for class for driving Princeton PT6312 VFD controller as used in C2233
   *
   * @brief Supports 7 Digits of 7 Segments and Icons. Also supports a scanned keyboard of 7 keys.
   *  
   * @param  PinName mosi, miso, sclk, cs SPI bus pins
   */
  PT6312_C2233(PinName mosi, PinName miso, PinName sclk, PinName cs);

#if DOXYGEN_ONLY
    /** Write a character to the Display
     *
     * @param c The character to write to the display
     */
    int putc(int c);

    /** Write a formatted string to the Display
     *
     * @param format A printf-style format string, followed by the
     *               variables to use in formatting the string.
     */
    int printf(const char* format, ...);   
#endif

     /** Locate cursor to a screen column
     *
     * @param column  The horizontal position from the left, indexed from 0
     */
    void locate(int column);
    
    /** Clear the screen and locate to 0
     * @param bool clrAll Clear Icons also (default = false)
     */
    void cls(bool clrAll = false);

    /** Set Icon
     *
     * @param Icon icon Enums Icon has Grid position encoded in 8 MSBs, Icon pattern encoded in 16 LSBs
     * @return none
     */
    void setIcon(Icon icon);

    /** Clr Icon
     *
     * @param Icon icon Enums Icon has Grid position encoded in 8 MSBs, Icon pattern encoded in 16 LSBs
     * @return none
     */
    void clrIcon(Icon icon);

   /** Set User Defined Characters (UDC)
     *
     * @param unsigned char udc_idx   The Index of the UDC (0..7)
     * @param int udc_data            The bitpattern for the UDC (16 bits)       
     */
    void setUDC(unsigned char udc_idx, int udc_data);


   /** Number of screen columns
    *
    * @param none
    * @return columns
    */
    int columns();   

   /** Write databyte to PT6312
     *  @param  int address display memory location to write byte
     *  @param  char data byte written at given address
     *  @return none
     */ 
    void writeData(int address, char data){
      PT6312::writeData(address, data);
    }        
 
   /** Write Display datablock to PT6312
    *  @param  DisplayData_t data Array of PT6312_DISPLAY_MEM (=22) bytes for displaydata (starting at address 0)
    *  @param  length number bytes to write (valid range 0..(DVD462_NR_GRIDS*2) (=14), starting at address 0)   
    *  @return none
    */   
    void writeData(DisplayData_t data, int length = (C2233_NR_GRIDS*2)) {
      PT6312::writeData(data, length);
    }  

protected:  
    // Stream implementation functions
    virtual int _putc(int value);
    virtual int _getc();

private:
    int _column;                     // Current cursor location
    int _columns;                    // Max number of columns
    
    DisplayData_t _displaybuffer;    // Local mirror for all chars and icons
    UDCData_t _UDC_7S;               // User Defined Character pattterns (UDC)        
};
#endif

#endif
