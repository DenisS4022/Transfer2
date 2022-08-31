// Adafruit GFX font rusMono17x15 size: 15x24

const uint8_t rusMono17x15Bitmaps[] PROGMEM = {
  0x49,0x24,0x92,0x48,0x01,0xF8,	// symbol '!'
  0xE7,0xE7,0x67,0x42,0x42,0x42,0x42,	// symbol
  0x09,0x02,0x41,0x10,0x44,0x11,0x1F,0xF1,0x10,0x4C,0x12,0x3F,0xE1,0x20,0x48,0x12,
  0x04,0x81,0x20,0x48,	// symbol '#'
  0x04,0x07,0xA2,0x19,0x12,0x44,0x11,0x03,0x00,0x3C,0x00,0x81,0x10,0x46,0x11,0xE0,
  0xA7,0xC0,0x40,0x10,0x04,0x00,	// symbol '$'
  0x78,0x66,0x21,0x10,0x8C,0xC3,0xC0,0x06,0x1C,0xF0,0x07,0x86,0x62,0x11,0x08,0xCC,
  0x3C,	// symbol '%'
  0x1C,0x11,0x10,0x48,0x24,0x21,0x21,0xA1,0xB3,0x8A,0x45,0x21,0x88,0xC7,0xB0,	// symbol '&'
  0xFD,0xA4,0x90,	// symbol '''
  0x29,0x29,0x24,0x92,0x44,0x91,0x20,	// symbol '('
  0x89,0x24,0x49,0x24,0x94,0x94,0x80,	// symbol ')'
  0x08,0x08,0x88,0x7F,0x18,0x14,0x24,0x42,	// symbol '*'
  0x08,0x04,0x02,0x01,0x00,0x87,0xFC,0x20,0x10,0x08,0x04,0x02,0x00,	// symbol '+'
  0x3B,0x9C,0xCE,0x62,0x00,	// symbol ','
  0xFF,0xE0,	// symbol '-'
  0xFF,0x80,	// symbol '.'
  0x00,0x80,0xC0,0x40,0x20,0x20,0x10,0x10,0x08,0x08,0x04,0x04,0x02,0x02,0x01,0x01,
  0x00,0x80,0x80,0x40,0x00,	// symbol '/'
  0x1C,0x31,0x90,0x58,0x38,0x0C,0x06,0x03,0x01,0x80,0xC0,0x60,0x30,0x34,0x13,0x18,
  0x70,	// digit '0'
  0x30,0xE1,0x44,0x81,0x02,0x04,0x08,0x10,0x20,0x40,0x81,0x1F,0xC0,	// digit '1'
  0x1E,0x10,0x90,0x68,0x10,0x08,0x0C,0x04,0x04,0x04,0x06,0x06,0x06,0x06,0x0E,0x07,
  0xFE,	// digit '2'
  0x7C,0x41,0x00,0x40,0x20,0x10,0x10,0x70,0x04,0x01,0x00,0x40,0x20,0x10,0x1E,0x19,
  0xF0,	// digit '3'
  0x06,0x0A,0x0A,0x12,0x22,0x22,0x42,0x42,0x82,0x82,0xFF,0x02,0x02,0x02,0x0F,	// digit '4'
  0x7F,0x20,0x10,0x08,0x04,0x02,0xF1,0x8C,0x03,0x00,0x80,0x40,0x20,0x18,0x16,0x18,
  0xF0,	// digit '5'
  0x0F,0x8C,0x08,0x08,0x04,0x04,0x02,0x79,0x46,0xC1,0xE0,0x60,0x28,0x14,0x19,0x08,
  0x78,	// digit '6'
  0xFF,0x81,0x81,0x02,0x02,0x02,0x02,0x04,0x04,0x04,0x04,0x08,0x08,0x08,0x08,	// digit '7'
  0x3E,0x31,0xB0,0x70,0x18,0x0C,0x05,0x8C,0x38,0x63,0x40,0x60,0x30,0x18,0x1B,0x18,
  0xF8,	// digit '8'
  0x3C,0x31,0x30,0x50,0x28,0x0C,0x0F,0x06,0x85,0x3C,0x80,0x40,0x40,0x20,0x20,0x63,
  0xE0,	// digit '9'
  0xFF,0x80,0x07,0xFC,	// symbol ':'
  0xFF,0x80,0x03,0x7F,0x68,	// symbol ';'
  0x00,0xC0,0xC0,0x60,0x60,0x60,0x30,0x03,0x00,0x30,0x03,0x00,0x60,0x04,	// symbol '<'
  0xFF,0xF0,0x00,0x00,0x0F,0xFF,	// symbol '='
  0xC0,0x0C,0x00,0xC0,0x0C,0x01,0x80,0x30,0x30,0x18,0x18,0x18,0x08,0x00,	// symbol '>'
  0x3E,0x60,0xA0,0x20,0x10,0x08,0x08,0x18,0x10,0x08,0x00,0x00,0x00,0x01,0xC0,0xE0,	// symbol '?'
  0x1E,0x04,0x31,0x01,0x43,0x28,0x93,0x21,0x64,0x2C,0x85,0x90,0xF1,0x2A,0x18,0xA0,
  0x04,0x00,0x63,0xC3,0x80,	// symbol '@'
  0x3C,0x00,0x80,0x28,0x05,0x00,0x90,0x22,0x04,0x41,0x04,0x3F,0x84,0x11,0x01,0x20,
  0x24,0x05,0xE3,0xC0,	// eng 'A'
  0xFF,0x08,0x11,0x01,0x20,0x24,0x04,0x81,0x1F,0xC2,0x06,0x40,0x68,0x05,0x00,0xA0,
  0x14,0x05,0xFF,0x00,	// eng 'B'
  0x1E,0x48,0x74,0x05,0x01,0x80,0x20,0x08,0x02,0x00,0x80,0x20,0x04,0x01,0x01,0x30,
  0x87,0xC0,	// eng 'C'
  0xFE,0x10,0x44,0x09,0x02,0x40,0x50,0x14,0x05,0x01,0x40,0x50,0x14,0x0D,0x02,0x41,
  0x3F,0x80,	// eng 'D'
  0xFF,0xC8,0x09,0x01,0x20,0x04,0x00,0x88,0x1F,0x02,0x20,0x40,0x08,0x01,0x00,0xA0,
  0x14,0x03,0xFF,0xC0,	// eng 'E'
  0xFF,0xE8,0x05,0x00,0xA0,0x04,0x00,0x88,0x1F,0x02,0x20,0x40,0x08,0x01,0x00,0x20,
  0x04,0x01,0xF0,0x00,	// eng 'F'
  0x1F,0x46,0x19,0x01,0x60,0x28,0x01,0x00,0x20,0x04,0x00,0x83,0xF0,0x0B,0x01,0x20,
  0x23,0x0C,0x3E,0x00,	// eng 'G'
  0xE0,0xE8,0x09,0x01,0x20,0x24,0x04,0x80,0x9F,0xF2,0x02,0x40,0x48,0x09,0x01,0x20,
  0x24,0x05,0xC1,0xC0,	// eng 'H'
  0xFE,0x20,0x40,0x81,0x02,0x04,0x08,0x10,0x20,0x40,0x81,0x1F,0xC0,	// eng 'I'
  0x0F,0xE0,0x10,0x02,0x00,0x40,0x08,0x01,0x00,0x20,0x04,0x80,0x90,0x12,0x02,0x40,
  0xC6,0x30,0x7C,0x00,	// eng 'J'
  0xF1,0xC8,0x11,0x04,0x21,0x04,0x40,0x90,0x17,0x03,0x30,0x43,0x08,0x21,0x02,0x20,
  0x44,0x0D,0xE0,0xC0,	// eng 'K'
  0xF8,0x04,0x00,0x80,0x10,0x02,0x00,0x40,0x08,0x01,0x00,0x20,0x04,0x04,0x80,0x90,
  0x12,0x03,0xFF,0xC0,	// eng 'L'
  0xE0,0x76,0x06,0x50,0xA5,0x0A,0x49,0x24,0x92,0x46,0x24,0x62,0x46,0x24,0x02,0x40,
  0x24,0x02,0x40,0x2F,0x0F,	// eng 'M'
  0xE0,0xF6,0x02,0x50,0x25,0x02,0x48,0x24,0xC2,0x44,0x24,0x22,0x43,0x24,0x12,0x40,
  0xA4,0x0A,0x40,0x6F,0x06,	// eng 'N'
  0x0F,0x03,0x0C,0x60,0x64,0x02,0x80,0x18,0x01,0x80,0x18,0x01,0x80,0x18,0x01,0x40,
  0x26,0x06,0x30,0xC0,0xF0,	// eng 'O'
  0xFF,0x88,0x19,0x00,0xA0,0x14,0x02,0x80,0xD0,0x33,0xFC,0x40,0x08,0x01,0x00,0x20,
  0x04,0x01,0xF0,0x00,	// eng 'P'
  0x0F,0x03,0x0C,0x60,0x64,0x02,0x80,0x18,0x01,0x80,0x18,0x01,0x80,0x18,0x01,0x40,
  0x26,0x06,0x30,0xC1,0xF0,0x0C,0x01,0xF1,0x30,0xE0,	// eng 'Q'
  0xFF,0x04,0x18,0x40,0xC4,0x04,0x40,0x44,0x0C,0x41,0x87,0xE0,0x43,0x04,0x10,0x40,
  0x84,0x04,0x40,0x4F,0x03,	// eng 'R'
  0x1F,0x48,0x34,0x05,0x01,0x40,0x08,0x01,0xC0,0x0E,0x00,0x40,0x18,0x06,0x01,0xE1,
  0xA7,0xC0,	// eng 'S'
  0xFF,0xF0,0x86,0x10,0x82,0x00,0x40,0x08,0x01,0x00,0x20,0x04,0x00,0x80,0x10,0x02,
  0x00,0x40,0x7F,0x00,	// eng 'T'
  0xF0,0xF4,0x02,0x40,0x24,0x02,0x40,0x24,0x02,0x40,0x24,0x02,0x40,0x24,0x02,0x40,
  0x22,0x04,0x30,0xC0,0xF0,	// eng 'U'
  0xF8,0xF2,0x02,0x20,0x41,0x04,0x10,0x81,0x08,0x08,0x80,0x90,0x09,0x00,0x50,0x06,
  0x00,0x60,0x02,0x00,0x20,	// eng 'V'
  0xF1,0xF4,0x02,0x40,0x24,0x42,0x44,0x42,0x64,0x26,0x42,0xA4,0x2A,0x42,0x94,0x11,
  0x41,0x14,0x11,0xC1,0x08,	// eng 'W'
  0x60,0x62,0x06,0x30,0x41,0x08,0x09,0x80,0x50,0x06,0x00,0x60,0x0D,0x00,0x88,0x10,
  0xC2,0x04,0x60,0x2F,0x0F,	// eng 'X'
  0xE1,0xE8,0x08,0x82,0x10,0x41,0x10,0x14,0x02,0x80,0x20,0x04,0x00,0x80,0x10,0x02,
  0x00,0x40,0x7F,0x00,	// eng 'Y'
  0xFF,0x40,0xA0,0x90,0x40,0x40,0x40,0x20,0x20,0x20,0x10,0x50,0x30,0x18,0x0F,0xFC,	// eng 'Z'
  0xF2,0x49,0x24,0x92,0x49,0x24,0x9C,	// symbol '['
  0x80,0x60,0x10,0x08,0x02,0x01,0x00,0x40,0x20,0x08,0x04,0x01,0x00,0x80,0x20,0x10,
  0x04,0x02,0x00,0x80,0x40,	// symbol '\'
  0xE4,0x92,0x49,0x24,0x92,0x49,0x3C,	// symbol ']'
  0x08,0x0C,0x09,0x0C,0x4C,0x14,0x04,	// symbol '^'
  0xFF,0xC0,	// symbol '_'
  0x84,0x21,	// symbol '`'
  0x3E,0x10,0x60,0x08,0x02,0x3F,0x98,0x28,0x0A,0x02,0xC3,0x9F,0x30,	// eng 'a'
  0xE0,0x02,0x00,0x20,0x02,0x00,0x20,0x02,0x78,0x28,0x43,0x02,0x20,0x12,0x01,0x20,
  0x12,0x01,0x30,0x22,0x86,0xE7,0x80,	// eng 'b'
  0x1F,0x58,0x34,0x06,0x01,0x80,0x20,0x08,0x01,0x00,0x60,0x47,0xE0,	// eng 'c'
  0x00,0xC0,0x08,0x01,0x00,0x20,0x04,0x3C,0x98,0x52,0x06,0x80,0x50,0x0A,0x01,0x40,
  0x24,0x0C,0xC2,0x87,0x98,	// eng 'd'
  0x3F,0x18,0x68,0x06,0x01,0xFF,0xE0,0x08,0x03,0x00,0x60,0xC7,0xC0,	// eng 'e'
  0x0F,0x98,0x08,0x04,0x02,0x07,0xF8,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01,0x03,
  0xF8,	// eng 'f'
  0x1E,0x6C,0x39,0x03,0x40,0x28,0x05,0x00,0xA0,0x12,0x06,0x61,0x43,0xC8,0x01,0x00,
  0x20,0x08,0x3E,0x00,	// eng 'g'
  0xC0,0x10,0x04,0x01,0x00,0x40,0x13,0x87,0x11,0x82,0x40,0x90,0x24,0x09,0x02,0x40,
  0x90,0x2E,0x1C,	// eng 'h'
  0x08,0x04,0x02,0x00,0x00,0x03,0xC0,0x20,0x10,0x08,0x04,0x02,0x01,0x00,0x80,0x43,
  0xFE,	// eng 'i'
  0x04,0x08,0x10,0x00,0x1F,0xC0,0x81,0x02,0x04,0x08,0x10,0x20,0x40,0x81,0x02,0x0B,
  0xE0,	// eng 'j'
  0xE0,0x02,0x00,0x20,0x02,0x00,0x20,0x02,0x3C,0x21,0x02,0x60,0x2C,0x03,0x80,0x24,
  0x02,0x20,0x21,0x02,0x08,0xE1,0xF0,	// eng 'k'
  0x78,0x04,0x02,0x01,0x00,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01,0x00,0x80,0x43,
  0xFE,	// eng 'l'
  0xDC,0xE3,0x19,0x90,0x84,0x84,0x24,0x21,0x21,0x09,0x08,0x48,0x42,0x42,0x17,0x18,
  0xC0,	// eng 'm'
  0x67,0x83,0x84,0x20,0x22,0x02,0x20,0x22,0x02,0x20,0x22,0x02,0x20,0x2F,0x07,	// eng 'n'
  0x1F,0x04,0x11,0x01,0x40,0x18,0x03,0x00,0x60,0x0A,0x02,0x20,0x83,0xE0,	// eng 'o'
  0xCF,0x85,0x06,0x60,0x24,0x01,0x40,0x14,0x01,0x40,0x16,0x02,0x50,0x44,0xF8,0x40,
  0x04,0x00,0x40,0x0F,0x00,	// eng 'p'
  0x1E,0x6C,0x3B,0x03,0x40,0x28,0x05,0x00,0xA0,0x12,0x06,0x61,0x43,0xC8,0x01,0x00,
  0x20,0x04,0x03,0xC0,	// eng 'q'
  0xE3,0x8B,0x13,0x80,0x80,0x20,0x08,0x02,0x00,0x80,0x20,0x3F,0x80,	// eng 'r'
  0x1F,0x58,0x34,0x05,0x80,0x1E,0x00,0x60,0x06,0x01,0xC0,0xAF,0xC0,	// eng 's'
  0x20,0x08,0x02,0x00,0x80,0xFF,0x08,0x02,0x00,0x80,0x20,0x08,0x02,0x00,0x80,0x30,
  0x47,0xE0,	// eng 't'
  0xC1,0xC8,0x09,0x01,0x20,0x24,0x04,0x80,0x90,0x12,0x02,0x61,0xC7,0xCC,	// eng 'u'
  0xF1,0xE8,0x09,0x02,0x30,0x42,0x10,0x42,0x04,0x40,0x90,0x0A,0x01,0x80,	// eng 'v'
  0xF0,0x7A,0x01,0x10,0x08,0x8C,0x42,0x62,0x12,0x90,0xA5,0x05,0x18,0x28,0xC0,0x86,
  0x00,	// eng 'w'
  0x78,0xF3,0x04,0x18,0x80,0xD0,0x06,0x00,0x70,0x09,0x81,0x0C,0x20,0x6F,0x8F,	// eng 'x'
  0xF0,0xF2,0x02,0x20,0x41,0x04,0x10,0x80,0x88,0x09,0x00,0x50,0x06,0x00,0x20,0x04,
  0x00,0x40,0x08,0x0F,0xE0,	// eng 'y'
  0xFF,0x41,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x40,0xBF,0xC0,	// eng 'z'
  0x19,0x08,0x42,0x10,0x84,0x64,0x18,0x42,0x10,0x84,0x20,0xC0,	// symbol '{'
  0xFF,0xFF,0xC0,	// symbol '|'
  0xC1,0x08,0x42,0x10,0x84,0x10,0x4C,0x42,0x10,0x84,0x26,0x00,	// symbol '}'
  0x38,0x13,0x38,0x38,	// symbol '~'
  0xFF,0x80,	// symbol '�'
  0x38,0x28,0x8A,0x0E,0x00,	// symbol '~�'
  0x78,0x86,0x80,0x60,0x38,0x46,0x81,0x81,0x42,0x3C,0x02,0x01,0xC2,0x3C,	// symbol '�'
  0x30,0xC0,0x00,0xFF,0xE4,0x02,0x40,0x24,0x00,0x40,0x04,0x20,0x7E,0x04,0x20,0x40,
  0x04,0x00,0x40,0x14,0x01,0x40,0x1F,0xFF,	// rus '�'
  0x07,0x00,0xC6,0x08,0x08,0x8E,0x24,0x89,0x44,0x06,0x20,0x31,0x01,0x88,0x0A,0x44,
  0x91,0xC4,0x40,0x41,0x8C,0x03,0x80,	// symbol '�'
  0x02,0x41,0x20,0x90,0x48,0x24,0x12,0x09,0x01,0x20,0x24,0x04,0x80,0x90,0x12,0x02,
  0x40,	// symbol '�'
  0x07,0x00,0xC6,0x08,0x08,0x9E,0x24,0x89,0x44,0x46,0x22,0x31,0xE1,0x88,0x8A,0x42,
  0x90,0x04,0x40,0x41,0x8C,0x03,0x80,	// symbol '�'
  0x74,0x63,0x18,0xB8,	// symbol '�'
  0x08,0x04,0x02,0x01,0x00,0x87,0xFC,0x20,0x10,0x08,0x04,0x02,0x00,0x00,0x07,0xFC,	// symbol '�'
  0xFF,0xFC,	// symbol '�'
  0xCF,0xFC,	// symbol '�'
  0xF0,0xE8,0x09,0x01,0x20,0x24,0x04,0x80,0x90,0x13,0x02,0x51,0xC9,0xCD,0x00,0x20,
  0x04,0x01,0x80,0x00,	// symbol '�'
  0x71,0xC4,0x10,0x00,0x1F,0xC6,0x0D,0x00,0x60,0x0F,0xFF,0x80,0x10,0x03,0x00,0x30,
  0x31,0xF8,	// rus '�'
  0x1C,0x00,0x40,0x0A,0x00,0xA0,0x09,0x01,0x10,0x11,0x02,0x08,0x3F,0x82,0x08,0x40,
  0x44,0x04,0x40,0x4F,0x0F,	// rus '�'
  0xFF,0xE4,0x02,0x40,0x24,0x00,0x40,0x04,0x00,0x7F,0x84,0x06,0x40,0x34,0x01,0x40,
  0x14,0x01,0x40,0x2F,0xFC,	// rus '�'
  0xFF,0x84,0x04,0x40,0x24,0x02,0x40,0x24,0x04,0x7F,0x84,0x06,0x40,0x34,0x01,0x40,
  0x14,0x01,0x40,0x2F,0xFC,	// rus '�'
  0xFF,0xF2,0x01,0x20,0x12,0x00,0x20,0x02,0x00,0x20,0x02,0x00,0x20,0x02,0x00,0x20,
  0x02,0x00,0x20,0x07,0x80,	// rus '�'
  0x3F,0xF0,0x41,0x02,0x08,0x10,0x40,0x82,0x04,0x10,0x20,0x82,0x04,0x10,0x20,0x81,
  0x0C,0x08,0x40,0x42,0x02,0x7F,0xFE,0x00,0x30,0x01,	// rus '�'
  0xFF,0xE4,0x02,0x40,0x24,0x00,0x40,0x04,0x40,0x7C,0x04,0x40,0x40,0x04,0x00,0x40,
  0x14,0x01,0x40,0x1F,0xFF,	// rus '�'
  0x62,0x31,0x11,0x08,0x88,0x44,0x41,0x24,0x09,0x20,0x3E,0x06,0x4C,0x22,0x22,0x10,
  0x90,0x84,0x84,0x24,0x21,0x79,0x1C,	// rus '�'
  0x1F,0x86,0x04,0x80,0x28,0x02,0x00,0x20,0x04,0x03,0x80,0x04,0x00,0x20,0x01,0x00,
  0x18,0x01,0x80,0x36,0x06,0x1F,0x80,	// rus '�'
  0xF0,0x74,0x06,0x40,0xA4,0x0A,0x41,0x24,0x32,0x42,0x24,0x42,0x4C,0x24,0x82,0x50,
  0x25,0x02,0x60,0x2E,0x0F,	// rus '�'
  0x19,0x80,0x60,0x00,0x0F,0x07,0x40,0x64,0x0A,0x40,0xA4,0x12,0x43,0x24,0x22,0x44,
  0x24,0xC2,0x48,0x25,0x02,0x50,0x26,0x02,0xE0,0xF0,	// rus '�'
  0xF0,0xE4,0x04,0x40,0x84,0x10,0x42,0x04,0x40,0x4E,0x07,0x30,0x41,0x84,0x08,0x40,
  0x44,0x04,0x40,0x6F,0x03,	// rus '�'
  0x3F,0xF0,0x40,0x82,0x04,0x10,0x20,0x81,0x04,0x08,0x20,0x41,0x02,0x08,0x10,0x40,
  0x84,0x04,0x20,0x22,0x01,0x60,0x3C,	// rus '�'
  0xE0,0x3B,0x01,0x94,0x14,0xA0,0xA4,0x89,0x24,0x49,0x14,0x48,0xA2,0x45,0x12,0x10,
  0x90,0x04,0x80,0x24,0x01,0x78,0x3C,	// rus '�'
  0xF0,0x74,0x02,0x40,0x24,0x02,0x40,0x24,0x02,0x7F,0xE4,0x02,0x40,0x24,0x02,0x40,
  0x24,0x02,0x40,0x2E,0x0F,	// rus '�'
  0x0F,0x03,0x0C,0x60,0x64,0x02,0x80,0x18,0x01,0x80,0x18,0x01,0x80,0x18,0x01,0x40,
  0x26,0x06,0x30,0xC0,0xF0,	// rus '�'
  0xFF,0xF4,0x02,0x40,0x24,0x02,0x40,0x24,0x02,0x40,0x24,0x02,0x40,0x24,0x02,0x40,
  0x24,0x02,0x40,0x2E,0x0F,	// rus '�'
  0xFF,0xC4,0x06,0x40,0x14,0x01,0x40,0x14,0x03,0x40,0x67,0xFC,0x40,0x04,0x00,0x40,
  0x04,0x00,0x40,0x0F,0x80,	// rus '�'
  0x0F,0x93,0x07,0x40,0x14,0x01,0x80,0x08,0x00,0x80,0x08,0x00,0x80,0x08,0x00,0x40,
  0x04,0x01,0x30,0x21,0xFC,	// rus '�'
  0xFF,0xFC,0x10,0x60,0x82,0x04,0x00,0x20,0x01,0x00,0x08,0x00,0x40,0x02,0x00,0x10,
  0x00,0x80,0x04,0x00,0x20,0x0F,0xE0,	// rus '�'
  0xF0,0xF2,0x02,0x20,0x41,0x04,0x10,0x80,0x88,0x09,0x00,0x50,0x06,0x00,0x20,0x04,
  0x00,0x40,0x08,0x0F,0x00,	// rus '�'
  0x07,0x00,0x10,0x07,0xF0,0xC4,0x64,0x21,0x41,0x06,0x08,0x30,0x41,0x82,0x0A,0x10,
  0x98,0x8C,0x3F,0x80,0x20,0x01,0x00,0x1C,0x00,	// rus '�'
  0xF0,0x79,0x01,0x8C,0x08,0x20,0x80,0x8C,0x02,0x40,0x0C,0x00,0xE0,0x0C,0x80,0x42,
  0x04,0x18,0x40,0x46,0x01,0x78,0x3C,	// rus '�'
  0xE0,0x72,0x01,0x10,0x08,0x80,0x44,0x02,0x20,0x11,0x00,0x88,0x04,0x40,0x22,0x01,
  0x10,0x08,0x80,0x44,0x02,0x7F,0xFC,0x00,0x20,0x01,	// rus '�'
  0xF0,0xF2,0x02,0x20,0x22,0x02,0x20,0x23,0x02,0x18,0x20,0x7E,0x00,0x20,0x02,0x00,
  0x20,0x02,0x00,0x20,0x0F,	// rus '�'
  0xE0,0x3A,0x00,0x91,0xC4,0x84,0x24,0x21,0x21,0x09,0x08,0x48,0x42,0x42,0x12,0x10,
  0x90,0x84,0x84,0x24,0x21,0x7F,0xFC,	// rus '�'
  0xE0,0x3A,0x00,0x91,0xC4,0x84,0x24,0x21,0x21,0x09,0x08,0x48,0x42,0x42,0x12,0x10,
  0x90,0x84,0x84,0x24,0x21,0x7F,0xFC,0x00,0x20,0x01,0x00,0x08,	// rus '�'
  0xFF,0x04,0x20,0x21,0x00,0x08,0x00,0x40,0x03,0xF0,0x10,0x40,0x81,0x04,0x08,0x20,
  0x41,0x02,0x08,0x10,0x41,0x0F,0xF0,	// rus '�'
  0xF0,0x7A,0x00,0x90,0x04,0x80,0x24,0x01,0x3F,0x09,0x04,0x48,0x12,0x40,0x92,0x04,
  0x90,0x24,0x81,0x24,0x11,0x7F,0x1C,	// rus '�'
  0xF0,0x08,0x01,0x00,0x20,0x04,0x00,0xFF,0x10,0x12,0x01,0x40,0x28,0x05,0x00,0xA0,
  0x14,0x05,0xFF,0x00,	// rus '�'
  0x3E,0x18,0x32,0x03,0x00,0x20,0x02,0x00,0x40,0x08,0x7F,0x00,0x20,0x04,0x01,0x40,
  0x6C,0x18,0x7C,0x00,	// rus '�'
  0xE0,0x82,0x1B,0x11,0x04,0x88,0x24,0x80,0xA4,0x05,0x20,0x2F,0x01,0x48,0x0A,0x40,
  0x51,0x04,0x88,0x24,0x36,0x70,0x40,	// rus '�'
  0x1F,0xF3,0x02,0x60,0x24,0x02,0x40,0x26,0x02,0x30,0x20,0xFE,0x18,0x21,0x02,0x20,
  0x24,0x02,0x40,0x2E,0x0F,	// rus '�'
  0x3F,0x08,0x18,0x01,0x00,0x23,0xFC,0xC0,0xA0,0x14,0x02,0xC1,0xCF,0xCC,	// rus '�'
  0x00,0x47,0xE3,0x01,0x80,0x40,0x20,0x0B,0xF3,0x02,0x80,0x60,0x18,0x05,0x02,0x3F,
  0x00,	// rus '�'
  0x0F,0x04,0x22,0x10,0x88,0x42,0x21,0x0B,0xF3,0x02,0x80,0x60,0x18,0x05,0x02,0x3F,
  0x00,	// rus '�'
  0x3F,0x88,0x08,0x00,0x80,0x61,0xF0,0xC0,0x20,0x04,0x01,0x40,0x47,0xF0,	// rus '�'
  0x1F,0x4C,0x19,0x01,0x40,0x28,0x05,0x00,0xA0,0x12,0x02,0x38,0xE0,0xEC,0x07,0x01,
  0x20,0x68,0x11,0x02,0x40,0x48,0x06,0x00,	// rus '�'
  0x3F,0x8C,0x1A,0x00,0xC0,0x1F,0xFF,0x00,0x20,0x06,0x00,0x60,0x63,0xF0,	// rus '�'
  0xE7,0x3A,0x10,0x88,0x88,0x24,0x80,0xF8,0x09,0x20,0x88,0x88,0x42,0x42,0x17,0x39,
  0xC0,	// rus '�'
  0x1F,0xC6,0x06,0x00,0x10,0x03,0x01,0xC0,0x02,0x00,0x1C,0x01,0x60,0x31,0xFC,	// rus '�'
  0xE0,0xF2,0x01,0x10,0x08,0x80,0x44,0x02,0x20,0x11,0x01,0x84,0x1C,0x21,0xA0,0xF8,
  0xC0,	// rus '�'
  0x09,0x00,0x30,0x00,0x01,0xC1,0xE4,0x02,0x20,0x11,0x00,0x88,0x04,0x40,0x22,0x03,
  0x08,0x38,0x43,0x41,0xF1,0x80,	// rus '�'
  0xE1,0xE1,0x04,0x08,0xC0,0x4C,0x03,0xC0,0x11,0x00,0x84,0x04,0x10,0x20,0x47,0x87,
  0xC0,	// rus '�'
  0x3F,0xE0,0x82,0x08,0x20,0x82,0x08,0x20,0x82,0x10,0x21,0x02,0x20,0x2F,0x07,	// rus '�'
  0xE0,0x3B,0x01,0x94,0x14,0xA0,0xA5,0x05,0x24,0x49,0x22,0x48,0xA2,0x42,0x17,0x11,
  0xC0,	// rus '�'
  0x70,0x72,0x02,0x20,0x22,0x02,0x3F,0xE2,0x02,0x20,0x22,0x02,0x20,0x2F,0x07,	// rus '�'
  0x1F,0x82,0x04,0x40,0x28,0x01,0x80,0x18,0x01,0x80,0x14,0x02,0x20,0x41,0xF8,	// rus '�'
  0xCF,0x85,0x04,0x60,0x24,0x02,0x40,0x24,0x02,0x40,0x24,0x02,0x40,0x2E,0x01,	// rus '�'
  0xCF,0xC2,0x81,0x98,0x04,0x80,0x14,0x00,0xA0,0x05,0x00,0x2C,0x02,0x50,0x22,0x7E,
  0x10,0x00,0x80,0x04,0x00,0x78,0x00,	// rus '�'
  0x1F,0xD6,0x03,0x40,0x18,0x01,0x80,0x08,0x00,0x80,0x04,0x00,0x60,0x11,0xFE,	// rus '�'
  0xCC,0x62,0x95,0x98,0xC4,0x84,0x24,0x21,0x21,0x09,0x08,0x48,0x42,0x42,0x17,0x10,
  0x40,	// rus '�'
  0xF0,0xF2,0x02,0x20,0x41,0x04,0x10,0x80,0x88,0x09,0x00,0x50,0x06,0x00,0x20,0x04,
  0x00,0x40,0x08,0x0F,0x00,	// rus '�'
  0x07,0x00,0x10,0x0F,0xF8,0x84,0x28,0x20,0xC1,0x06,0x08,0x30,0x41,0x82,0x0A,0x10,
  0x8F,0xF8,0x04,0x00,0x20,0x01,0x00,0x08,0x01,0xF0,	// rus '�'
  0xF0,0xF6,0x04,0x30,0x81,0x90,0x0E,0x00,0xB0,0x11,0x82,0x0C,0x40,0x6F,0x0F,	// rus '�'
  0xE0,0xF2,0x01,0x10,0x08,0x80,0x44,0x02,0x20,0x11,0x01,0x84,0x1C,0x21,0xA0,0xF8,
  0xC0,0x02,0x00,0x60,	// rus '�'
  0xE0,0xE4,0x04,0x40,0x44,0x04,0x20,0x41,0xFC,0x00,0x40,0x04,0x00,0x40,0x0F,	// rus '�'
  0xE0,0xE8,0x89,0x11,0x22,0x24,0x44,0x88,0x91,0x12,0x22,0x44,0x5F,0xFC,	// rus '�'
  0xE0,0xE4,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x4F,0xFF,0x00,
  0x10,0x01,0x00,0x10,	// rus '�'
  0xFF,0x04,0x20,0x21,0x00,0x08,0x00,0x40,0x03,0xF0,0x10,0x40,0x81,0x04,0x08,0x20,
  0x83,0xF8,	// rus '�'
  0xE0,0xF4,0x02,0x40,0x24,0x02,0x7E,0x24,0x12,0x40,0xA4,0x0A,0x41,0x2F,0xE7,	// rus '�'
  0xE0,0x10,0x04,0x01,0x00,0x7F,0x10,0x24,0x05,0x01,0x40,0xBF,0xC0,	// rus '�'
  0x3F,0x10,0x2C,0x04,0x01,0x0F,0xC0,0x1C,0x06,0x01,0x40,0x8F,0xC0,	// rus '�'
  0xE3,0xC4,0x42,0x44,0x24,0x81,0x48,0x17,0x81,0x48,0x14,0x42,0x44,0x2E,0x3C,	// rus '�'
  0x1F,0xE4,0x09,0x01,0x20,0x22,0x04,0x3F,0x88,0x12,0x02,0x40,0x5C,0x1C	// rus '�'
};

const GFXglyph rusMono17x15Glyphs[] PROGMEM = {
  { 0, 0, 0, 15, 0, 7 },	// SPC
  { 0, 3, 15, 15, 1, -14 },	// symbol '!'
  { 6, 8, 7, 15, 1, -14 },	// symbol
  { 13, 10, 16, 15, 0, -14 },	// symbol '#'
  { 33, 10, 17, 15, 0, -14 },	// symbol '$'
  { 55, 9, 15, 15, 1, -14 },	// symbol '%'
  { 72, 9, 13, 15, 1, -12 },	// symbol '&'
  { 87, 3, 7, 15, 3, -14 },	// symbol '''
  { 90, 3, 17, 15, 2, -13 },	// symbol '('
  { 97, 3, 17, 15, 2, -13 },	// symbol ')'
  { 104, 8, 8, 15, 1, -13 },	// symbol '*'
  { 112, 9, 11, 15, 1, -11 },	// symbol '+'
  { 125, 5, 7, 15, 1, -3 },	// symbol ','
  { 130, 11, 1, 15, 0, -6 },	// symbol '-'
  { 132, 3, 3, 15, 1, -2 },	// symbol '.'
  { 134, 9, 18, 15, 1, -15 },	// symbol '/'
  { 155, 9, 15, 15, 1, -14 },	// digit '0'
  { 172, 7, 14, 15, 0, -13 },	// digit '1'
  { 185, 9, 15, 15, 0, -14 },	// digit '2'
  { 202, 9, 15, 15, 0, -14 },	// digit '3'
  { 219, 8, 15, 15, 0, -14 },	// digit '4'
  { 234, 9, 15, 15, 0, -14 },	// digit '5'
  { 251, 9, 15, 15, 0, -14 },	// digit '6'
  { 268, 8, 15, 15, 0, -14 },	// digit '7'
  { 283, 9, 15, 15, 0, -14 },	// digit '8'
  { 300, 9, 15, 15, 0, -14 },	// digit '9'
  { 317, 3, 10, 15, 1, -9 },	// symbol ':'
  { 321, 3, 13, 15, 1, -9 },	// symbol ';'
  { 326, 10, 11, 15, 0, -11 },	// symbol '<'
  { 340, 12, 4, 15, 0, -8 },	// symbol '='
  { 346, 10, 11, 15, 0, -11 },	// symbol '>'
  { 360, 9, 14, 15, 1, -13 },	// symbol '?'
  { 376, 11, 15, 15, 0, -13 },	// symbol '@'
  { 397, 11, 14, 15, 0, -13 },	// eng 'A'
  { 417, 11, 14, 15, 0, -13 },	// eng 'B'
  { 437, 10, 14, 15, 0, -13 },	// eng 'C'
  { 455, 10, 14, 15, 0, -13 },	// eng 'D'
  { 473, 11, 14, 15, 0, -13 },	// eng 'E'
  { 493, 11, 14, 15, 0, -13 },	// eng 'F'
  { 513, 11, 14, 15, 0, -13 },	// eng 'G'
  { 533, 11, 14, 15, 0, -13 },	// eng 'H'
  { 553, 7, 14, 15, 0, -13 },	// eng 'I'
  { 566, 11, 14, 15, 0, -13 },	// eng 'J'
  { 586, 11, 14, 15, 0, -13 },	// eng 'K'
  { 606, 11, 14, 15, 0, -13 },	// eng 'L'
  { 626, 12, 14, 15, 0, -13 },	// eng 'M'
  { 647, 12, 14, 15, 0, -13 },	// eng 'N'
  { 668, 12, 14, 15, 0, -13 },	// eng 'O'
  { 689, 11, 14, 15, 0, -13 },	// eng 'P'
  { 709, 12, 17, 15, 0, -13 },	// eng 'Q'
  { 735, 12, 14, 15, 0, -13 },	// eng 'R'
  { 756, 10, 14, 15, 0, -13 },	// eng 'S'
  { 774, 11, 14, 15, 0, -13 },	// eng 'T'
  { 794, 12, 14, 15, 0, -13 },	// eng 'U'
  { 815, 12, 14, 15, 0, -13 },	// eng 'V'
  { 836, 12, 14, 15, 0, -13 },	// eng 'W'
  { 857, 12, 14, 15, 0, -13 },	// eng 'X'
  { 878, 11, 14, 15, 0, -13 },	// eng 'Y'
  { 898, 9, 14, 15, 0, -13 },	// eng 'Z'
  { 914, 3, 18, 15, 1, -14 },	// symbol '['
  { 921, 9, 18, 15, 1, -15 },	// symbol '\'
  { 942, 3, 18, 15, 1, -14 },	// symbol ']'
  { 949, 9, 6, 15, 1, -14 },	// symbol '^'
  { 956, 10, 1, 15, 1, 0 },	// symbol '_'
  { 958, 4, 4, 15, 2, -15 },	// symbol '`'
  { 960, 10, 10, 15, 0, -9 },	// eng 'a'
  { 973, 12, 15, 15, 0, -14 },	// eng 'b'
  { 996, 10, 10, 15, 0, -9 },	// eng 'c'
  { 1009, 11, 15, 15, 0, -14 },	// eng 'd'
  { 1030, 10, 10, 15, 0, -9 },	// eng 'e'
  { 1043, 9, 15, 15, 0, -14 },	// eng 'f'
  { 1060, 11, 14, 15, 0, -9 },	// eng 'g'
  { 1080, 10, 15, 15, 0, -14 },	// eng 'h'
  { 1099, 9, 15, 15, 0, -14 },	// eng 'i'
  { 1116, 7, 19, 15, 0, -14 },	// eng 'j'
  { 1133, 12, 15, 15, 0, -14 },	// eng 'k'
  { 1156, 9, 15, 15, 0, -14 },	// eng 'l'
  { 1173, 13, 10, 15, 0, -9 },	// eng 'm'
  { 1190, 12, 10, 15, 0, -9 },	// eng 'n'
  { 1205, 11, 10, 15, 0, -9 },	// eng 'o'
  { 1219, 12, 14, 15, 0, -9 },	// eng 'p'
  { 1240, 11, 14, 15, 0, -9 },	// eng 'q'
  { 1260, 10, 10, 15, 0, -9 },	// eng 'r'
  { 1273, 10, 10, 15, 0, -9 },	// eng 's'
  { 1286, 10, 14, 15, 0, -13 },	// eng 't'
  { 1304, 11, 10, 15, 0, -9 },	// eng 'u'
  { 1318, 11, 10, 15, 0, -9 },	// eng 'v'
  { 1332, 13, 10, 15, 0, -9 },	// eng 'w'
  { 1349, 12, 10, 15, 0, -9 },	// eng 'x'
  { 1364, 12, 14, 15, 0, -9 },	// eng 'y'
  { 1385, 9, 10, 15, 0, -9 },	// eng 'z'
  { 1397, 5, 18, 15, 1, -14 },	// symbol '{'
  { 1409, 1, 18, 15, 3, -14 },	// symbol '|'
  { 1412, 5, 18, 15, 1, -14 },	// symbol '}'
  { 1424, 10, 3, 15, 0, -7 },	// symbol '~'
  { 1428, 0, 0, 15, 0, 7 },	// DEL
  { 1428, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1428, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1428, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1428, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1428, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1428, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1428, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1428, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1428, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1428, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1428, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1428, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1428, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1428, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1428, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1428, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1428, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1428, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1428, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1428, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1428, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1428, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1428, 9, 1, 15, 1, -9 },	// symbol '�'
  { 1430, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1430, 11, 3, 15, 0, -10 },	// symbol '~�'
  { 1435, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1435, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1435, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1435, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1435, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1435, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1435, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1435, 0, 0, 15, 0, 7 },	// char '160'
  { 1435, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1435, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1435, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1435, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1435, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1435, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1435, 8, 14, 15, 1, -13 },	// symbol '�'
  { 1449, 12, 16, 15, 0, -15 },	// rus '�'
  { 1473, 13, 14, 15, 0, -13 },	// symbol '�'
  { 1496, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1496, 10, 13, 15, 1, -13 },	// symbol '�'
  { 1513, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1513, 0, 0, 15, 0, 7 },	// char '173'
  { 1513, 13, 14, 15, 0, -13 },	// symbol '�'
  { 1536, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1536, 5, 6, 15, 6, -12 },	// symbol '�'
  { 1540, 9, 14, 15, 1, -14 },	// symbol '�'
  { 1556, 1, 14, 15, 4, -13 },	// symbol '�'
  { 1558, 1, 14, 15, 4, -13 },	// symbol '�'
  { 1560, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1560, 11, 14, 15, 0, -9 },	// symbol '�'
  { 1580, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1580, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1580, 11, 13, 15, 0, -12 },	// rus '�'
  { 1598, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1598, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1598, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1598, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1598, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1598, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1598, 0, 0, 15, 0, 7 },	// symbol '�'
  { 1598, 12, 14, 15, 0, -13 },	// rus '�'
  { 1619, 12, 14, 15, 0, -13 },	// rus '�'
  { 1640, 12, 14, 15, 0, -13 },	// rus '�'
  { 1661, 12, 14, 15, 0, -13 },	// rus '�'
  { 1682, 13, 16, 15, 0, -13 },	// rus '�'
  { 1708, 12, 14, 15, 0, -13 },	// rus '�'
  { 1729, 13, 14, 15, 0, -13 },	// rus '�'
  { 1752, 12, 15, 15, 0, -14 },	// rus '�'
  { 1775, 12, 14, 15, 0, -13 },	// rus '�'
  { 1796, 12, 17, 15, 0, -16 },	// rus '�'
  { 1822, 12, 14, 15, 0, -13 },	// rus '�'
  { 1843, 13, 14, 15, 0, -13 },	// rus '�'
  { 1866, 13, 14, 15, 0, -13 },	// rus '�'
  { 1889, 12, 14, 15, 0, -13 },	// rus '�'
  { 1910, 12, 14, 15, 0, -13 },	// rus '�'
  { 1931, 12, 14, 15, 0, -13 },	// rus '�'
  { 1952, 12, 14, 15, 0, -13 },	// rus '�'
  { 1973, 12, 14, 15, 0, -13 },	// rus '�'
  { 1994, 13, 14, 15, 0, -13 },	// rus '�'
  { 2017, 12, 14, 15, 0, -13 },	// rus '�'
  { 2038, 13, 15, 15, 0, -14 },	// rus '�'
  { 2063, 13, 14, 15, 0, -13 },	// rus '�'
  { 2086, 13, 16, 15, 0, -13 },	// rus '�'
  { 2112, 12, 14, 15, 0, -13 },	// rus '�'
  { 2133, 13, 14, 15, 0, -13 },	// rus '�'
  { 2156, 13, 17, 15, 0, -13 },	// rus '�'
  { 2184, 13, 14, 15, 0, -13 },	// rus '�'
  { 2207, 13, 14, 15, 0, -13 },	// rus '�'
  { 2230, 11, 14, 15, 0, -13 },	// rus '�'
  { 2250, 11, 14, 15, 0, -13 },	// rus '�'
  { 2270, 13, 14, 15, 0, -13 },	// rus '�'
  { 2293, 12, 14, 15, 0, -13 },	// rus '�'
  { 2314, 11, 10, 15, 0, -9 },	// rus '�'
  { 2328, 10, 13, 15, 0, -12 },	// rus '�'
  { 2345, 10, 13, 15, 0, -12 },	// rus '�'
  { 2362, 11, 10, 15, 0, -9 },	// rus '�'
  { 2376, 11, 17, 15, 0, -9 },	// rus '�'
  { 2400, 11, 10, 15, 0, -9 },	// rus '�'
  { 2414, 13, 10, 15, 0, -9 },	// rus '�'
  { 2431, 12, 10, 15, 0, -9 },	// rus '�'
  { 2446, 13, 10, 15, 0, -9 },	// rus '�'
  { 2463, 13, 13, 15, 0, -12 },	// rus '�'
  { 2485, 13, 10, 15, 0, -9 },	// rus '�'
  { 2502, 12, 10, 15, 0, -9 },	// rus '�'
  { 2517, 13, 10, 15, 0, -9 },	// rus '�'
  { 2534, 12, 10, 15, 0, -9 },	// rus '�'
  { 2549, 12, 10, 15, 0, -9 },	// rus '�'
  { 2564, 12, 10, 15, 0, -9 },	// rus '�'
  { 2579, 13, 14, 15, 0, -9 },	// rus '�'
  { 2602, 12, 10, 15, 0, -9 },	// rus '�'
  { 2617, 13, 10, 15, 0, -9 },	// rus '�'
  { 2634, 12, 14, 15, 0, -9 },	// rus '�'
  { 2655, 13, 16, 15, 0, -10 },	// rus '�'
  { 2681, 12, 10, 15, 0, -9 },	// rus '�'
  { 2696, 13, 12, 15, 0, -9 },	// rus '�'
  { 2716, 12, 10, 15, 0, -9 },	// rus '�'
  { 2731, 11, 10, 15, 0, -9 },	// rus '�'
  { 2745, 12, 13, 15, 0, -9 },	// rus '�'
  { 2765, 13, 11, 15, 0, -10 },	// rus '�'
  { 2783, 12, 10, 15, 0, -9 },	// rus '�'
  { 2798, 10, 10, 15, 0, -9 },	// rus '�'
  { 2811, 10, 10, 15, 0, -9 },	// rus '�'
  { 2824, 12, 10, 15, 0, -9 },	// rus '�'
  { 2839, 11, 10, 15, 0, -9 }	// rus '�'
};

const GFXfont rusMono17x15 PROGMEM = {
 (uint8_t *)rusMono17x15Bitmaps,
 (GFXglyph *)rusMono17x15Glyphs,
 32, 255, 24};