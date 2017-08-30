#include "gf2ext-iso.h"
#include <stdint.h>

static uint32_t generator_96[4] __attribute__((aligned(32))) = {0x00000104,0x00000000,0x00000000,0x00000000};

static uint32_t generator_128[4] __attribute__((aligned(32))) = {0x00000100,0x00000000,0x00000000,0x00000000};

const uint8_t * g_tbl_96 = (const uint8_t *) generator_96;

const uint8_t * g_tbl_128 = (const uint8_t *) generator_128;



static uint32_t isomor_96[4*96] __attribute__((aligned(32))) = {
0x00000001,0x00000000,0x00000000,0x00000000,
0x00000104,0x00000000,0x00000000,0x00000000,
0x00010003,0x00000000,0x00000000,0x00000000,
0x0104030c,0x00000000,0x00000000,0x00000000,
0x00000005,0x00000001,0x00000000,0x00000000,
0x00000507,0x00000104,0x00000000,0x00000000,
0x0005000f,0x00010003,0x00000000,0x00000000,
0x05070f09,0x0104030c,0x00000000,0x00000000,
0x00000002,0x00000000,0x00000001,0x00000000,
0x00000208,0x00000000,0x00000104,0x00000000,
0x00020006,0x00000000,0x00010003,0x00000000,
0x0208060b,0x00000000,0x0104030c,0x00000000,
0x0000001a,0x00000002,0x00000005,0x00000000,
0x00001a4e,0x00000208,0x00000507,0x00000000,
0x001a003d,0x00020006,0x0005000f,0x00000000,
0x1a4e3dc1,0x0208060b,0x05070f09,0x00000000,
0x00000004,0x00000010,0x00000000,0x00000000,
0x00000403,0x00001040,0x00000000,0x00000000,
0x0004000c,0x00100030,0x00000000,0x00000000,
0x04030c05,0x104030c0,0x00000000,0x00000000,
0x00000007,0x00000054,0x00000010,0x00000000,
0x0000070f,0x00005473,0x00001040,0x00000000,
0x00070009,0x005400fc,0x00100030,0x00000000,
0x070f0902,0x5473fc95,0x104030c0,0x00000000,
0x0800010a,0x00000020,0x00000004,0x00000000,
0x06010e0e,0x00002088,0x00000403,0x00000000,
0x0a0a030d,0x00200860,0x0004000c,0x00000000,
0x040d0101,0x208866ba,0x04030c05,0x00000000,
0x0e000544,0x080001aa,0x00000027,0x00000000,
0x0d054333,0x0601aee0,0x00002787,0x00000000,
0x04440fcc,0x0aaa0ddd,0x00270869,0x00000000,
0x473cc555,0xa4e3dc15,0x27876fb8,0x00000000,
0x00000003,0x00000000,0x08000102,0x00000000,
0x0000038c,0x00000000,0x06010608,0x00000000,
0x00038005,0x00000000,0x0a020306,0x00000000,
0x038c65a7,0x00000000,0x0c0b0a0b,0x00000000,
0x8000102f,0x00000003,0x0e00050a,0x00000000,
0x60106f69,0x0000038c,0x0d050d0e,0x00000000,
0xa02fd062,0x00038005,0x040a0f0d,0x00000000,
0xcf5972f8,0x038c65a7,0x09010401,0x00000000,
0x00000006,0x80001020,0x03000207,0x00000000,
0x0000063b,0x60106080,0x0c020f8f,0x00000000,
0x0006300a,0xa0203060,0x07078609,0x00000000,
0x063bca7e,0xc0b0a0b0,0x088962a2,0x00000000,
0x3000207d,0xe00050a6,0x8f001a28,0x00000000,
0xcc20f502,0xd050d6db,0x691a6666,0x00000000,
0x70759394,0x40a6c0d6,0xa828dd6b,0x00000000,
0x8a64b2a4,0x962b866b,0xce5b7afa,0x00000000,
0x00010008,0x000c0030,0x06000408,0x00000000,
0x01040866,0x0c0530c0,0x0b040b06,0x00000000,
0x000b600b,0x00370051,0x0e080c07,0x00000000,
0x0b6abbea,0x37cf5174,0x050a020f,0x00000000,
0x6005408e,0x000800f8,0x0d0c073e,0x00000000,
0xb547bebd,0x0806f8f6,0x0d0231cd,0x00000000,
0xe0811071,0x00f3602e,0x03390959,0x00000000,
0x517431c4,0xf3fc9e6d,0x35cb5b72,0x00000000,
0x0bc20305,0x600b40e0,0x0c01080b,0x00000000,
0xc85b09c7,0xbb4ad0db,0x040c0d6a,0x00000000,
0x0d73c51f,0xe0eecbd2,0x0f086b05,0x00000000,
0x723948b9,0x3e168815,0x016dbfe7,0x00000000,
0xc18a8fb2,0xdbc37335,0x690e4ee1,0x00000000,
0xdbe1dd34,0xd92fc906,0xbc43dc0f,0x00000000,
0xfc092e06,0x3d4054d0,0xe6e01ad0,0x00000000,
0x952c8564,0x8164a3ec,0x3bca9e2d,0x00000000,
0x00000005,0x00100040,0x00c00000,0x00000000,
0x00000507,0x10404030,0xc0500000,0x00000000,
0x0a050c04,0x007000c0,0x00700010,0x00000000,
0x0b0b0103,0x70f0c05a,0x70f01040,0x00000000,
0x0c0b0002,0x00500a75,0x00800040,0x00000000,
0x0e0a0208,0x507a7bfb,0x80604030,0x00000000,
0x0b0c0805,0x0a850194,0x00f00090,0x00000000,
0x060d0307,0x8b669028,0xf090902a,0x00000000,
0x07020402,0x0c2b0880,0x00b00a05,0x00000000,
0x0d0c0108,0x2e828667,0xb0aa0b0b,0x00000000,
0x0a040703,0x0fee0cb2,0x0ae50124,0x00000000,
0x0a040cac,0xe7d1b7a2,0xebd6208c,0x00000000,
0x030fa75a,0x0ea30de2,0x0c3b0c82,0x00000000,
0x03aeb5be,0xaee1e3db,0x3ec68766,0x00000000,
0xa9581a4b,0x0c370719,0x0bdc0915,0x00000000,
0xba6c058a,0x32c816eb,0xd61c174b,0x00000000,
0xc0b08007,0x0040a060,0x07520408,0x00000000,
0xe020677f,0x40908070,0x5d7c0b06,0x00000000,
0xfee7c523,0xa0a01010,0x0dfe0c4b,0x00000000,
0x7a1a745c,0x40f050be,0xff914e9a,0x00000000,
0xe53aa088,0xc0c0ced7,0x086aa76e,0x00000000,
0xed6e68e6,0x909e8afa,0x6c19817d,0x00000000,
0xbad55617,0xbea79473,0xacc31961,0x00000000,
0x74416688,0x0a7b5046,0x2645230a,0x00000000,
0xb1523102,0x75aa364f,0xce148604,0x00000000,
0xfc49cae3,0x5dd88488,0x49c56f76,0x00000000,
0xdaf8b944,0xa992eb9a,0xf738cfa6,0x00000000,
0xe72fe94e,0x70c340f4,0xa709ff42,0x00000000,
0xff60964a,0x331cc474,0xe6fddb48,0x00000000,
0xf0266f51,0xd081270c,0x264a5205,0x00000000,
0xb5e4ea10,0x914383f5,0xc16c7dd7,0x00000000,
0x4939c25b,0x67bf9922,0x38c8268e,0x00000000,
};

static uint32_t ivs_iso_96[4*96] __attribute__((aligned(32))) = {
0x00000001,0x00000000,0x00000000,0x00000000,
0x9c1992d3,0xb442e5dd,0xb1ce9115,0x00000000,
0xb25ee8a7,0xc869881c,0xd99e9d2c,0x00000000,
0xabca35eb,0x7eea9dbb,0xfd5073d4,0x00000000,
0x53884fe6,0xde5d33b7,0xceede81a,0x00000000,
0x9c6e7d5e,0x1669f4cf,0x86063b0d,0x00000000,
0x15dc86e5,0xf029e8bc,0xf9ad8cab,0x00000000,
0xba50b1f7,0x0513bfa5,0x8ecf3775,0x00000000,
0xb25ee8a5,0xc869881c,0xd99e9d2c,0x00000000,
0xfd1842e2,0x163e2008,0x9ecd5bfb,0x00000000,
0x96451133,0x24c083ec,0x02f3a148,0x00000000,
0x1732430d,0x81af20be,0x92f0e195,0x00000000,
0xdc2d4b86,0x4cc2f9da,0x6476569a,0x00000000,
0xec6d19e4,0x29912032,0x82c34b6b,0x00000000,
0x8abe6ddd,0x28366008,0xbbb0c044,0x00000000,
0x93f2cafa,0xec361530,0x6235d348,0x00000000,
0x9c1992d6,0xb442e5dd,0xb1ce9115,0x00000000,
0x83e39466,0xad8216a7,0xaf6a5c67,0x00000000,
0x63cc8821,0x97d6afcd,0x42b48447,0x00000000,
0x2bd88764,0x31f19490,0xb9df339c,0x00000000,
0x32e4fad1,0xb1b393bd,0x735c6d70,0x00000000,
0x25c9ab9d,0xbf45235d,0x67b34f9a,0x00000000,
0x4bdddb77,0x356e6ff1,0x91d4977d,0x00000000,
0x4136e1cd,0xd9cb6a5b,0xfd182dbe,0x00000000,
0x351eff22,0xff02127e,0x2129ac68,0x00000000,
0x42fefd07,0x6aa4cfd7,0xe70b8157,0x00000000,
0xd86316f2,0x366dace0,0x9bcdc5fd,0x00000000,
0xd97f4020,0x59e6e642,0x9e60b51c,0x00000000,
0x2e142ed5,0x5609488b,0x776c4d9c,0x00000000,
0x0aa5b6f7,0xa7412ce1,0x327eb28b,0x00000000,
0xee77b50d,0x647b190a,0x37460614,0x00000000,
0x8298e1df,0x39ecee12,0x0c57899e,0x00000000,
0xb25ee8b6,0xc869881c,0xd99e9d2c,0x00000000,
0x3263e881,0x8cfe0fe4,0x5077bdb6,0x00000000,
0xa9c77d6e,0xf92cf260,0xf1b9acc1,0x00000000,
0x4682391a,0xef55d9ba,0x40072496,0x00000000,
0xb25fe8a7,0xc869881c,0xd99e9d2c,0x00000000,
0x97d38c31,0x776eb7d0,0x68aaec89,0x00000000,
0xf85ef238,0x39be567f,0x2b9ef33f,0x00000000,
0xe1e3c044,0xb0e3e9ce,0x1d97a7a3,0x00000000,
0xa39bfead,0x69ae9451,0x42849c9c,0x00000000,
0x2245e818,0xf6a9c672,0xe0e85ffb,0x00000000,
0xbd52a844,0xb69f1531,0x6a9a731d,0x00000000,
0x16a0e7db,0xab794ef0,0x21c0585a,0x00000000,
0xf20071d9,0xa93c304e,0x98a3c362,0x00000000,
0xce44d826,0x5e3e866f,0xccc27eb1,0x00000000,
0xd53180e6,0xcc7b9333,0xe60997db,0x00000000,
0xac4afe81,0x2f173232,0x781b50f1,0x00000000,
0xfa65551e,0x65c23d92,0xef934a25,0x00000000,
0x3cca6544,0x467bb41c,0xe010eda9,0x00000000,
0xfb7b463d,0xf2397840,0x7758255c,0x00000000,
0xb2568fea,0x16c44ea3,0xc9f29c53,0x00000000,
0x5fd031fb,0x9e5285a6,0xd74e1b1a,0x00000000,
0x5e221c62,0x933b48e5,0xe19fa797,0x00000000,
0xf8c6fa9c,0x6fa4e64e,0x98729860,0x00000000,
0x43e0a5c2,0xcc6b7139,0xdafd4888,0x00000000,
0x6150beae,0x39ec756d,0xa87ebb12,0x00000000,
0xa52317cd,0x9a625093,0x09d34d05,0x00000000,
0x3059bc20,0xc7cb790f,0xe133ed35,0x00000000,
0xcdfd6e02,0x999b2713,0x04adfa57,0x00000000,
0x2987cbc5,0x53509b0a,0x36eea451,0x00000000,
0x9145cfa9,0xea4c96fb,0x19c20da3,0x00000000,
0x9e9e8a0e,0xd27177d6,0x06348649,0x00000000,
0x4fc4ffd5,0x64183ad1,0xcc17a4e2,0x00000000,
0x9c1993d3,0xb442e5dd,0xb1ce9115,0x00000000,
0x87bb4198,0xad5f8634,0x170b605c,0x00000000,
0xca21838c,0x2c49a1e8,0x63ca2678,0x00000000,
0x0e8077e9,0x6e9f67bb,0xe1bb549f,0x00000000,
0xcd911d84,0x74d041c2,0x6be9ceeb,0x00000000,
0x6d4f6087,0xb0811726,0xff93bfa5,0x00000000,
0x85ff1070,0x1dfee25c,0x2345a561,0x00000000,
0xfeb3e8a2,0xf05ce287,0x87d9c82a,0x00000000,
0x9cf3f685,0x449d1c5b,0x00570e57,0x00000000,
0x01f6f4d9,0x34206bd2,0xcfad9426,0x00000000,
0x8fe1d553,0x418e2038,0x6151bdb9,0x00000000,
0x3e7b7f69,0x5c799ea2,0xb7b7e51e,0x00000000,
0x1edd2b78,0xf45e61d9,0xf49638b7,0x00000000,
0x4acc7b03,0x910fbac3,0x78febd65,0x00000000,
0xab205de3,0xffac925d,0xd2f13b8c,0x00000000,
0x7b36f31c,0x4d97467d,0xd3658095,0x00000000,
0xb6063859,0xc8b4188f,0x61ffa117,0x00000000,
0x5377c474,0x34683f0e,0x28ecc756,0x00000000,
0x82c6a8fa,0xf3a137f8,0x0d59e103,0x00000000,
0x9c008df7,0xcd0c00a6,0xc193e9a7,0x00000000,
0xf87b59bc,0x174127e7,0x3bdd40e7,0x00000000,
0xeeae051a,0x6f8833fb,0x2298fa5e,0x00000000,
0x6cb0b912,0x9a5989a9,0x298af8cf,0x00000000,
0x79609277,0xf5dcd26c,0x0cc48dc7,0x00000000,
0xeecad848,0x62c906e7,0xcea6a32c,0x00000000,
0x3aef051f,0xa5dc7eba,0x904a670b,0x00000000,
0xe0fcadd9,0x1b9e4870,0x53a0a446,0x00000000,
0x875125cf,0x5d807fb3,0xa692ff1e,0x00000000,
0x9c460a6a,0xb4dbc666,0x5e307901,0x00000000,
0xa43c9843,0x2accb59b,0x49f5797b,0x00000000,
0xcfb42e82,0x4c7a074e,0x4a504b26,0x00000000,
0x70df98e6,0x1e681e8a,0x129b191e,0x00000000,
};

static uint32_t isomor_128[4*128] __attribute__((aligned(32))) = {
0x00000001,0x00000000,0x00000000,0x00000000,
0x00000100,0x00000000,0x00000000,0x00000000,
0x00010000,0x00000000,0x00000000,0x00000000,
0x01000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000001,0x00000000,0x00000000,
0x00000000,0x00000100,0x00000000,0x00000000,
0x00000000,0x00010000,0x00000000,0x00000000,
0x00000000,0x01000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x00000001,0x00000000,
0x00000000,0x00000000,0x00000100,0x00000000,
0x00000000,0x00000000,0x00010000,0x00000000,
0x00000000,0x00000000,0x01000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000001,
0x00000000,0x00000000,0x00000000,0x00000100,
0x00000000,0x00000000,0x00000000,0x00010000,
0x00000000,0x00000000,0x00000000,0x01000000,
0x00000010,0x00000000,0x00000000,0x00000000,
0x00001000,0x00000000,0x00000000,0x00000000,
0x00100000,0x00000000,0x00000000,0x00000000,
0x10000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000010,0x00000000,0x00000000,
0x00000000,0x00001000,0x00000000,0x00000000,
0x00000000,0x00100000,0x00000000,0x00000000,
0x00000000,0x10000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x00000010,0x00000000,
0x00000000,0x00000000,0x00001000,0x00000000,
0x00000000,0x00000000,0x00100000,0x00000000,
0x00000000,0x00000000,0x10000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000010,
0x00000000,0x00000000,0x00000000,0x00001000,
0x00000000,0x00000000,0x00000000,0x00100000,
0x00000000,0x00000000,0x00000000,0x10000000,
0x01000102,0x00000000,0x00000000,0x00000000,
0x00010200,0x00000001,0x00000000,0x00000000,
0x01020000,0x00000100,0x00000000,0x00000000,
0x02000000,0x00010001,0x00000000,0x00000000,
0x00000000,0x01000102,0x00000000,0x00000000,
0x00000000,0x00010200,0x00000001,0x00000000,
0x00000000,0x01020000,0x00000100,0x00000000,
0x00000000,0x02000000,0x00010001,0x00000000,
0x00000000,0x00000000,0x01000102,0x00000000,
0x00000000,0x00000000,0x00010200,0x00000001,
0x00000000,0x00000000,0x01020000,0x00000100,
0x00000000,0x00000000,0x02000000,0x00010001,
0x00000000,0x00000000,0x00000000,0x01000102,
0x00000010,0x00000000,0x00000000,0x00010200,
0x00001000,0x00000000,0x00000000,0x01020000,
0x00100010,0x00000000,0x00000000,0x02000000,
0x10001020,0x00000000,0x00000000,0x00000000,
0x00102000,0x00000010,0x00000000,0x00000000,
0x10200000,0x00001000,0x00000000,0x00000000,
0x20000000,0x00100010,0x00000000,0x00000000,
0x00000000,0x10001020,0x00000000,0x00000000,
0x00000000,0x00102000,0x00000010,0x00000000,
0x00000000,0x10200000,0x00001000,0x00000000,
0x00000000,0x20000000,0x00100010,0x00000000,
0x00000000,0x00000000,0x10001020,0x00000000,
0x00000000,0x00000000,0x00102000,0x00000010,
0x00000000,0x00000000,0x10200000,0x00001000,
0x00000000,0x00000000,0x20000000,0x00100010,
0x00000000,0x00000000,0x00000000,0x10001020,
0x01000102,0x00000000,0x00000000,0x00102000,
0x00010200,0x00000001,0x00000000,0x10200000,
0x00020102,0x00000100,0x00000000,0x20000000,
0x00010004,0x00010000,0x00000000,0x00000000,
0x01000400,0x01000000,0x00000000,0x00000000,
0x00040000,0x00000001,0x00000001,0x00000000,
0x04000000,0x00000100,0x00000100,0x00000000,
0x00000000,0x00010004,0x00010000,0x00000000,
0x00000000,0x01000400,0x01000000,0x00000000,
0x00000000,0x00040000,0x00000001,0x00000001,
0x00000000,0x04000000,0x00000100,0x00000100,
0x00000000,0x00000000,0x00010004,0x00010000,
0x00000000,0x00000000,0x01000400,0x01000000,
0x00000010,0x00000000,0x00040000,0x00000001,
0x00001000,0x00000000,0x04000000,0x00000100,
0x00100000,0x00000000,0x00000000,0x00010004,
0x10000000,0x00000000,0x00000000,0x01000400,
0x00000010,0x00000010,0x00000000,0x00040000,
0x00001000,0x00001000,0x00000000,0x04000000,
0x00100040,0x00100000,0x00000000,0x00000000,
0x10004000,0x10000000,0x00000000,0x00000000,
0x00400000,0x00000010,0x00000010,0x00000000,
0x40000000,0x00001000,0x00001000,0x00000000,
0x00000000,0x00100040,0x00100000,0x00000000,
0x00000000,0x10004000,0x10000000,0x00000000,
0x00000000,0x00400000,0x00000010,0x00000010,
0x00000000,0x40000000,0x00001000,0x00001000,
0x00000000,0x00000000,0x00100040,0x00100000,
0x00000000,0x00000000,0x10004000,0x10000000,
0x01000102,0x00000000,0x00400000,0x00000010,
0x00010200,0x00000001,0x40000000,0x00001000,
0x01020000,0x00000100,0x00000000,0x00100040,
0x02000000,0x00010001,0x00000000,0x10004000,
0x01000102,0x01000102,0x00000000,0x00400000,
0x00010200,0x00010201,0x00000001,0x40000000,
0x05020408,0x01020100,0x00000100,0x00000000,
0x02040800,0x02010005,0x00010001,0x00000000,
0x04080000,0x01000502,0x01000102,0x00000000,
0x08000000,0x00050204,0x00010201,0x00000001,
0x00000000,0x05020408,0x01020100,0x00000100,
0x00000000,0x02040800,0x02010005,0x00010001,
0x00000000,0x04080000,0x01000502,0x01000102,
0x00000010,0x08000000,0x00050204,0x00010201,
0x00001000,0x00000000,0x05020408,0x01020100,
0x00100010,0x00000000,0x02040800,0x02010005,
0x10001020,0x00000000,0x04080000,0x01000502,
0x00102010,0x00000010,0x08000000,0x00050204,
0x10201000,0x00001000,0x00000000,0x05020408,
0x20100050,0x00100010,0x00000000,0x02040800,
0x10005020,0x10001020,0x00000000,0x04080000,
0x00502040,0x00102010,0x00000010,0x08000000,
0x50204080,0x10201000,0x00001000,0x00000000,
0x20408000,0x20100050,0x00100010,0x00000000,
0x40800000,0x10005020,0x10001020,0x00000000,
0x80000000,0x00502040,0x00102010,0x00000010,
0x00000000,0x50204080,0x10201000,0x00001000,
0x00000000,0x20408000,0x20100050,0x00100010,
0x00000000,0x40800000,0x10005020,0x10001020,
0x01000102,0x80000000,0x00502040,0x00102010,
0x00010200,0x00000001,0x50204080,0x10201000,
0x00020102,0x00000100,0x20408000,0x20100050,
0x00010004,0x00010000,0x40800000,0x10005020,
0x00000502,0x01000000,0x80000000,0x00502040,
0x00050200,0x00000000,0x00000001,0x50204080,
0x0002050a,0x00000000,0x00000100,0x20408000,
0x00050804,0x00000000,0x00010000,0x40800000,
0x01080008,0x00000000,0x01000000,0x80000000,
};

static uint32_t ivs_iso_128[4*128] __attribute__((aligned(32))) = {
0x00000001,0x00000000,0x00000000,0x00000000,
0x0000000a,0x00000001,0x00000000,0x00000000,
0x00000044,0x00000000,0x00000001,0x00000000,
0x000002a8,0x00000044,0x0000000a,0x00000001,
0x00010000,0x00000000,0x00000000,0x00000000,
0x000a0000,0x00010000,0x00000000,0x00000000,
0x00440000,0x00000000,0x00010000,0x00000000,
0x02a80000,0x00440000,0x000a0000,0x00010000,
0x00000002,0x00000000,0x00000000,0x00000000,
0x00000014,0x00000002,0x00000000,0x00000000,
0x00000088,0x00000000,0x00000002,0x00000000,
0x00000550,0x00000088,0x00000014,0x00000002,
0x00020000,0x00000000,0x00000000,0x00000000,
0x00140000,0x00020000,0x00000000,0x00000000,
0x00880000,0x00000000,0x00020000,0x00000000,
0x05500000,0x00880000,0x00140000,0x00020000,
0x00000004,0x00000000,0x00000000,0x00000000,
0x00000028,0x00000004,0x00000000,0x00000000,
0x00000110,0x00000000,0x00000004,0x00000000,
0x00000aa0,0x00000110,0x00000028,0x00000004,
0x00040000,0x00000000,0x00000000,0x00000000,
0x00280000,0x00040000,0x00000000,0x00000000,
0x01100000,0x00000000,0x00040000,0x00000000,
0x0aa00000,0x01100000,0x00280000,0x00040000,
0x00000008,0x00000000,0x00000000,0x00000000,
0x00000050,0x00000008,0x00000000,0x00000000,
0x00000220,0x00000000,0x00000008,0x00000000,
0x00001540,0x00000220,0x00000050,0x00000008,
0x00080000,0x00000000,0x00000000,0x00000000,
0x00500000,0x00080000,0x00000000,0x00000000,
0x02200000,0x00000000,0x00080000,0x00000000,
0x15400000,0x02200000,0x00500000,0x00080000,
0x00000010,0x00000000,0x00000000,0x00000000,
0x000000a0,0x00000010,0x00000000,0x00000000,
0x00000440,0x00000000,0x00000010,0x00000000,
0x00002a80,0x00000440,0x000000a0,0x00000010,
0x00100000,0x00000000,0x00000000,0x00000000,
0x00a00000,0x00100000,0x00000000,0x00000000,
0x04400000,0x00000000,0x00100000,0x00000000,
0x2a800000,0x04400000,0x00a00000,0x00100000,
0x00000020,0x00000000,0x00000000,0x00000000,
0x00000140,0x00000020,0x00000000,0x00000000,
0x00000880,0x00000000,0x00000020,0x00000000,
0x00005500,0x00000880,0x00000140,0x00000020,
0x00200000,0x00000000,0x00000000,0x00000000,
0x01400000,0x00200000,0x00000000,0x00000000,
0x08800000,0x00000000,0x00200000,0x00000000,
0x55000000,0x08800000,0x01400000,0x00200000,
0x00000040,0x00000000,0x00000000,0x00000000,
0x00000280,0x00000040,0x00000000,0x00000000,
0x00001100,0x00000000,0x00000040,0x00000000,
0x0000aa00,0x00001100,0x00000280,0x00000040,
0x00400000,0x00000000,0x00000000,0x00000000,
0x02800000,0x00400000,0x00000000,0x00000000,
0x11000000,0x00000000,0x00400000,0x00000000,
0xaa000000,0x11000000,0x02800000,0x00400000,
0x00000080,0x00000000,0x00000000,0x00000000,
0x00000500,0x00000080,0x00000000,0x00000000,
0x00002200,0x00000000,0x00000080,0x00000000,
0x00015400,0x00002200,0x00000500,0x00000080,
0x00800000,0x00000000,0x00000000,0x00000000,
0x05000000,0x00800000,0x00000000,0x00000000,
0x22000000,0x00000000,0x00800000,0x00000000,
0x54000000,0x22000001,0x05000000,0x00800000,
0x00000100,0x00000000,0x00000000,0x00000000,
0x00000a00,0x00000100,0x00000000,0x00000000,
0x00004400,0x00000000,0x00000100,0x00000000,
0x0002a800,0x00004400,0x00000a00,0x00000100,
0x01000000,0x00000000,0x00000000,0x00000000,
0x0a000000,0x01000000,0x00000000,0x00000000,
0x44000000,0x00000000,0x01000000,0x00000000,
0xa8000000,0x44000002,0x0a000000,0x01000000,
0x00000200,0x00000000,0x00000000,0x00000000,
0x00001400,0x00000200,0x00000000,0x00000000,
0x00008800,0x00000000,0x00000200,0x00000000,
0x00055000,0x00008800,0x00001400,0x00000200,
0x02000000,0x00000000,0x00000000,0x00000000,
0x14000000,0x02000000,0x00000000,0x00000000,
0x88000000,0x00000000,0x02000000,0x00000000,
0x50000000,0x88000005,0x14000000,0x02000000,
0x00000400,0x00000000,0x00000000,0x00000000,
0x00002800,0x00000400,0x00000000,0x00000000,
0x00011000,0x00000000,0x00000400,0x00000000,
0x000aa000,0x00011000,0x00002800,0x00000400,
0x04000000,0x00000000,0x00000000,0x00000000,
0x28000000,0x04000000,0x00000000,0x00000000,
0x10000000,0x00000001,0x04000000,0x00000000,
0xa0000000,0x1000000a,0x28000001,0x04000000,
0x00000800,0x00000000,0x00000000,0x00000000,
0x00005000,0x00000800,0x00000000,0x00000000,
0x00022000,0x00000000,0x00000800,0x00000000,
0x00154000,0x00022000,0x00005000,0x00000800,
0x08000000,0x00000000,0x00000000,0x00000000,
0x50000000,0x08000000,0x00000000,0x00000000,
0x20000000,0x00000002,0x08000000,0x00000000,
0x40000000,0x20000015,0x50000002,0x08000000,
0x00001000,0x00000000,0x00000000,0x00000000,
0x0000a000,0x00001000,0x00000000,0x00000000,
0x00044000,0x00000000,0x00001000,0x00000000,
0x002a8000,0x00044000,0x0000a000,0x00001000,
0x10000000,0x00000000,0x00000000,0x00000000,
0xa0000000,0x10000000,0x00000000,0x00000000,
0x40000000,0x00000004,0x10000000,0x00000000,
0x80000000,0x4000002a,0xa0000004,0x10000000,
0x00002000,0x00000000,0x00000000,0x00000000,
0x00014000,0x00002000,0x00000000,0x00000000,
0x00088000,0x00000000,0x00002000,0x00000000,
0x00550000,0x00088000,0x00014000,0x00002000,
0x20000000,0x00000000,0x00000000,0x00000000,
0x40000000,0x20000001,0x00000000,0x00000000,
0x80000000,0x00000008,0x20000000,0x00000000,
0x00000000,0x80000055,0x40000008,0x20000001,
0x00004000,0x00000000,0x00000000,0x00000000,
0x00028000,0x00004000,0x00000000,0x00000000,
0x00110000,0x00000000,0x00004000,0x00000000,
0x00aa0000,0x00110000,0x00028000,0x00004000,
0x40000000,0x00000000,0x00000000,0x00000000,
0x80000000,0x40000002,0x00000000,0x00000000,
0x00000000,0x00000011,0x40000000,0x00000000,
0x00000000,0x000000aa,0x80000011,0x40000002,
0x00008000,0x00000000,0x00000000,0x00000000,
0x00050000,0x00008000,0x00000000,0x00000000,
0x00220000,0x00000000,0x00008000,0x00000000,
0x01540000,0x00220000,0x00050000,0x00008000,
0x80000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x80000005,0x00000000,0x00000000,
0x00000000,0x00000022,0x80000000,0x00000000,
0x00000000,0x00000154,0x00000022,0x80000005,
};




const unsigned char * isomorphism_96 = (unsigned char *)isomor_96;

const unsigned char * ivs_isomorphism_96 = (unsigned char *)ivs_iso_96;

const unsigned char * isomorphism_128 = (unsigned char *)isomor_128;

const unsigned char * ivs_isomorphism_128 = (unsigned char *)ivs_iso_128;
