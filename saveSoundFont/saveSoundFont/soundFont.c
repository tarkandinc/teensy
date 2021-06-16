//#include <AudioStream.h>
#include "samples.h"
#include "soundFont.h"
#include <stdint.h>
#include <WProgram.h>

uint8_t range = 127;

int16_t sampleCount = 640;

struct instrument_data instrument = {1, &range, &sample };

struct sample_data sample = {
    (int16_t*)soundSample, // sample
    true, // LOOP
    (int)11, // LENGTH_BITS
    (float)(1 << (32 - 11)) * CENTS_SHIFT(29) * 44100.0 / NOTE(94) / AUDIO_SAMPLE_RATE_EXACT + 0.5, // PER_HERTZ_PHASE_INCREMENT
    ((uint32_t)1188 - 1) << (32 - 11), // MAX_PHASE
    ((uint32_t)1184 - 1) << (32 - 11), // LOOP_PHASE_END
    (((uint32_t)1184 - 1) << (32 - 11)) - (((uint32_t)1136 - 1) << (32 - 11)), // LOOP_PHASE_LENGTH
    (uint16_t)(UINT16_MAX * DECIBEL_SHIFT(-4.5)), // INITIAL_ATTENUATION_SCALAR
    (uint32_t)(0.00 * SAMPLES_PER_MSEC / ENVELOPE_PERIOD + 0.5), // DELAY_COUNT
    (uint32_t)(6.00 * SAMPLES_PER_MSEC / ENVELOPE_PERIOD + 0.5), // ATTACK_COUNT
    (uint32_t)(20.01 * SAMPLES_PER_MSEC / ENVELOPE_PERIOD + 0.5), // HOLD_COUNT
    (uint32_t)(20.01 * SAMPLES_PER_MSEC / ENVELOPE_PERIOD + 0.5), // DECAY_COUNT
    (uint32_t)(100.02 * SAMPLES_PER_MSEC / ENVELOPE_PERIOD + 0.5), // RELEASE_COUNT
    (int32_t)((1.0 - DECIBEL_SHIFT(-4.4)) * UNITY_GAIN), // SUSTAIN_MULT
    (uint32_t)(0.00 * SAMPLES_PER_MSEC / (2 * LFO_PERIOD)), // VIBRATO_DELAY
    (uint32_t)(0.1 * LFO_PERIOD * (UINT32_MAX / AUDIO_SAMPLE_RATE_EXACT)), // VIBRATO_INCREMENT
    (CENTS_SHIFT(0) - 1.0) * 4, // VIBRATO_PITCH_COEFFICIENT_INITIAL
    (1.0 - CENTS_SHIFT(0)) * 4, // VIBRATO_COEFFICIENT_SECONDARY
    (uint32_t)(260.01 * SAMPLES_PER_MSEC / (2 * LFO_PERIOD)), // MODULATION_DELAY
    (uint32_t)(5.0 * LFO_PERIOD * (UINT32_MAX / AUDIO_SAMPLE_RATE_EXACT)), // MODULATION_INCREMENT
    (CENTS_SHIFT(9) - 1.0) * 4, // MODULATION_PITCH_COEFFICIENT_INITIAL
    (1.0 - CENTS_SHIFT(-9)) * 4, // MODULATION_PITCH_COEFFICIENT_SECOND
    (int32_t)(UINT16_MAX * (DECIBEL_SHIFT(0) - 1.0)) * 4, // MODULATION_AMPLITUDE_INITIAL_GAIN
    (int32_t)(UINT16_MAX * (1.0 - DECIBEL_SHIFT(0))) * 4, // MODULATION_AMPLITUDE_FINAL_GAIN
};

uint32_t soundSample[640] = {
0x00000000,0xfd01fe72,0xfe91fdb3,0x0078ff95,0x0151012b,0x023501b6,0x03360299,0x03cd041a,
0x03a10321,0x039703e5,0x03ab03f1,0x042e03ab,0x040c041a,0x032a03a9,0x02e802b8,0x015201c6,
0xff8e003b,0xfc99fe09,0xfa8ffbe4,0xf90ff979,0xf8eff93f,0xf7a0f846,0xf9f3f884,0xfb8ffade,
0xfc60fba4,0xff15fd93,0x01da00a8,0x03b4024e,0x05490482,0x06be065e,0x07a40738,0x05ec071d,
0x04370549,0x02fe030b,0x01b30250,0x00c0013e,0xff5dffb7,0xffaafef7,0xff3effc0,0xfda2fdf6,
0xfb10fc38,0xf937fa9c,0xf6e6f73d,0xf62cf6c4,0xf751f68a,0xf95df7c2,0xfac4f9d1,0xfe44fc6e,
0x0178ff89,0x04d5032c,0x07430616,0x0a0208ae,0x0c9b0b53,0x0cd90ccf,0x09660b4c,0x042d0681,
0xffe70285,0xfc67fddc,0xf9bbfb2b,0xf957f971,0xfb85fa9e,0xfe00fc9a,0xfe15feb4,0xfd32fd66,
0xf9c7fba4,0xf75ff839,0xf559f64d,0xf6f5f62e,0xf8e5f7cf,0xfc73fa8e,0x00dcfe48,0x02fa0249,
0x064f0414,0x097b07c2,0x0cfa0aed,0x11b70f68,0x127912e1,0x0cd40ff9,0x03e507e2,0xfc8d007a,
0xf47cf830,0xeed0f151,0xed09ed7d,0xf328ef37,0xfbd9f753,0x014affa7,0x018f01a8,0xfda2ffeb,
0xf910fb8e,0xf6fbf751,0xf6fcf62f,0xfaf4f901,0x004cfd5b,0x02b70222,0x02b8032a,0x040a0376,
0x07e805e4,0x0c800a2c,0x16761073,0x1b3219d4,0x111b175f,0x05400a29,0xff0701a4,0xf273fad1,
0xdfd9e946,0xdd52d9a1,0xe781e23e,0xfac5f098,0x08310277,0x070e092d,0x029e0541,0xfe09ff4b,
0xfb8ffc9c,0xfc39fb65,0x0086fdbf,0x055c03c7,0x030104cc,0xfe230051,0xfb2dfc4b,0xfc94fb07,
0x05860038,0x150f0bc8,0x222b1ca0,0x1a012229,0x06200de2,0x0e3b058b,0x00591140,0xcbcfe08f,
0xc3bcc1aa,0xe048d235,0xf7ffec68,0x0d0f08cd,0x06fb0bec,0x00ca0313,0x08d50573,0x06d30952,
0x08ab0511,0x11c90e1c,0x0cc812d9,0xfd8b04e0,0xf3d0f800,0xef70f2a4,0xe8e4ea90,0xf515eaf0,
0x0d7c02af,0x211818bd,0x2c952b55,0x0d0c206c,0x153a05e6,0x264732bb,0xb35de93f,0xb8b4ae05,
0xdc6ac060,0xee7eeda6,0x108a00a3,0x00ef09cc,0xfb2bfa4a,0x0f500664,0x0f57127a,0x1bbe104c,
0x2ae12730,0x078c1d8b,0xf142f6bf,0xf8a9f0da,0xfa8d0209,0xc1d6e16a,0xe158c5dc,0x03c2f4fe,
0x23bd11e6,0x3da42f84,0x1e3536f2,0xffc701d0,0x4b262007,0xdac434aa,0xaf689bca,0xc3c6c247,
0xedf1e843,0xff9ae8cf,0xf42c0404,0xedf1f11c,0x08e8f44c,0x1d571a46,0x2d03228c,0x33a534f8,
0x08ec216e,0xdf2ff05b,0x2b8ff116,0x03ad3faf,0x8b22a937,0xcb39be9e,0x00c3e7cf,0x21230b08,
0x2f0632de,0x206d25b8,0x17bd1ced,0x1fa910a3,0x441948a4,0xacdf03b5,0xd856af29,0xcda5c59a,
0xeb33e835,0xf8bae7aa,0xda0cec47,0xe7ead8b3,0x2d041025,0x2cd32e32,0x2f492ba2,0x1f052eea,
0xe0baff03,0x38e5ebb7,0x205a690e,0x8c0cac77,0xabc5b79f,0xef12bf66,0x08aaf6fa,0x26e12ad2,
0x13091a22,0x234212c7,0x2c4736ef,0x157f14bc,0x4f8d4345,0xb6030bc0,0xd2b3b7ee,0xcbd3b454,
0xfb9bf1aa,0xdd26e8a4,0xc305c45e,0x09b2e55f,0x38df29ea,0x27c233be,0x33a32a37,0x039727a8,
0xfd65e7ec,0x6f0e3e3f,0x9f9e1fbe,0xc2d0969a,0xbc9ba27c,0xeaa1e9ab,0x1c87ff0a,0x10771a22,
0x096c0b81,0x32d522bd,0x31e23c47,0x0b151402,0x5a8935b0,0xd1f12c9a,0xc1a39cc6,0xc25cc1c7,
0x075c05aa,0xa10abf6c,0xe5f9bff6,0x2095042e,0x31152c21,0x2cbb2c35,0x2ac72bb1,0xfafd1646,
0x216ef7cf,0x49265b77,0x8f94e18f,0xbb33b8aa,0xdcc3a71e,0xe2cbeb6e,0x0fc6fe6a,0x08fa0c26,
0x12fc0478,0x39c33427,0x2d6d3401,0x035815bb,0x5be01eda,0xecdb4f8e,0xb8109dee,0xb94eca10,
0xf7a9f9bd,0x9148aa54,0x027cd840,0x21ff175c,0x2a1f1f14,0x2ed0307c,0x1fc9246c,0xff0c1226,
0x3add0c61,0x2aba5d64,0x9cc0c7c1,0xb327c6e4,0xed91b84e,0xd3aae584,0x09dff35e,0x053c08cd,
0x1a530404,0x399b373f,0x2b083218,0x017116c5,0x5b23173f,0x02bc64f2,0xa7aaa0b6,0xad7dc9e5,
0xfd00e4f5,0x918cb33e,0x1160df7a,0x17981800,0x26a7134c,0x2a712f2e,0x1dfb2130,0x08141763,
0x427d150c,0x21bd5d4b,0x9e9bc0b6,0xb4a2c75b,0xf826c1b9,0xc1dde3a5,0x09abe994,0xfef3ffc7,
0x1f070a29,0x3f993b85,0x28873010,0x018c1c27,0x52780f91,0x18cc6e1a,0x9e1aa7e2,0xad2cce44,
0xfc09d0e7,0x988cc199,0x1219deac,0x14c90f5e,0x1eed134f,0x2a31294b,0x211a246f,0x0db91fe3,
0x3ba8101f,0x2c1c5e32,0xa200cc11,0xba7fc804,0xf5febe33,0xb940e33e,0x0332d3ce,0x04d50581,
0x1e5d0ea9,0x42483a63,0x21e031eb,0x053b1843,0x485a0ed2,0x2bd972dd,0x95dcb1d4,0xb25acba7,
0xf98bbb10,0xa3b1dd1e,0x0d49d081,0x09a70eb0,0x151e035f,0x30a52c74,0x21ca2787,0x18e32778,
0x2e840cef,0x3e245a76,0xa4f9e0e5,0xc457c1b7,0xe4acadc8,0xbd5ceb7b,0x058aca9a,0x04070bc1,
0x1cd00b47,0x409839ed,0x1ad62aab,0x14df1e4e,0x383e0f59,0x41726a25,0x95accaf1,0xc033c3b4,
0xf175ad13,0xb08af436,0x02ebba95,0xfd5808b1,0x1431012b,0x350b3108,0x26972f55,0x1dc0271b,
0x1eb90b07,0x50cd51e3,0xac5afa0b,0xc9a1b415,0xd4a3a4e6,0xc941f804,0xfd09bd86,0xff270d0e,
0x1c850a7c,0x39eb3063,0x1aba2ac9,0x21462274,0x2234101f,0x56f45ac4,0xa16eeedc,0xcc90b8ec,
0xda0ba3d2,0xc16efe7c,0xed12a777,0xfe26096f,0x13ea05cc,0x34712b94,0x263732cc,0x23e821cf,
0x145c1047,0x5c204488,0xb6f113bb,0xd081a946,0xbf66abeb,0xdd4af8ae,0xe6bcba2f,0xff280862,
0x18ee0b85,0x35d728bd,0x1e1a2e5d,0x2d8f23db,0x0fbd1662,0x69294498,0xb68a1d47,0xcf66a6de,
0xb834a9d7,0xdc4cfb65,0xd55ba862,0x02c00985,0x0d3404c9,0x31f11fb9,0x2a4036db,0x27731eb0,
0x0d4c1cef,0x5a062b5d,0xd0213315,0xc88ea30b,0xac26bd01,0xf2c8f3bc,0xc93db902,0x02440349,
0x13f706a2,0x306b2011,0x28d93397,0x2f41214a,0x0a7b223a,0x65bd2cfa,0xd7e9421c,0xc046a1a9,
0xa248bd3b,0xf5a2ebb1,0xbba0b678,0x061c009d,0x0941ff0a,0x304519e9,0x2edb3817,0x26901d68,
0x0cd428de,0x4baf12a0,0xf6ee4e79,0xba7bafdc,0xa581ce22,0xfc88d5c5,0xb87fcefa,0x055ff256,
0x11630244,0x2e1c1b08,0x2e6635e6,0x28c21fc7,0x11932d29,0x4eb9162f,0x061c5ceb,0xa8cbae14,
0xa44cca85,0x02a7c9db,0xafeed79a,0x06a4e665,0x0654f84f,0x26081476,0x36383808,0x1f372049,
0x15a02d30,0x318c024e,0x25885f1d,0xa9ddc766,0xaed1cc43,0xfb69b468,0xb8fcecaf,0x06f5d722,
0x0b8b01d0,0x241115fc,0x3157326d,0x1f742261,0x23973208,0x2ba80b6c,0x367f5fb6,0x9b81cc73,
0xbd73c6c4,0xf524aa24,0xb740f586,0xfe8dc1b6,0x0523ffb4,0x1d1c10f3,0x38e8338c,0x184d2867,
0x235f2766,0x149d0328,0x4e935588,0xaa16ef4e,0xc726baec,0xe36fa494,0xcc530229,0xf696bf29,
0x05940320,0x1a621489,0x328c2b7d,0x1ddb2abd,0x312b2bb4,0x0f221024,0x552247a8,0xa8d5fb9d,
0xd2beb375,0xcf51a5cf,0xd04100a2,0xe891b174,0xff6804c4,0x197d0dee,0x35fa2bc0,0x17c02c69,
0x2d001e40,0x02a50feb,0x5f5c37d9,0xc451231c,0xcbe2a7a4,0xb9cdaafe,0xea73016a,0xd986b9f3,
0x039f055c,0x16eb10c2,0x308a21d7,0x21f13185,0x34532104,0x00d91dac,0x5c6c2746,0xcdde2fbe,
0xce43a7f0,0xac31b757,0xefaaf5a2,0xc92db83a,0x026d007f,0x17270b03,0x2fb0221d,0x21592f18,
0x2cd81ad8,0xfed3211d,0x58b01954,0xe9c74af7,0xbd35a6e2,0xa4fcc07f,0x005bea67,0xc0e8ca82,
0x08d6f96b,0x13e00c2b,0x2a531995,0x2a8f3217,0x2dfc1eb2,0x05862bf3,0x4dc60cc8,0xfac35568,
0xb7cbac3a,0x9fb6c89a,0x0279d883,0xb661cfa6,0x05d6eef3,0x13c70472,0x281b1cb0,0x2b252ebe,
0x24881dff,0x06fb28f6,0x42e80568,0x0f2c5cff,0xaefab56c,0xa402c8f6,0x03dbd082,0xb8dad68f,
0x067aec9e,0x13aa0561,0x28091c8c,0x2b252ebc,0x24881dff,0x06fb28f6,0x42e80568,0x0f2c5cff,
0xaefab56c,0xa402c8f6,0x03dbd082,0xb8dad68f,0x067aec9e,0x13aa0561,0x28091c8c,0x2b252ebc,
0x25b51f2b,0x00002045,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
};
