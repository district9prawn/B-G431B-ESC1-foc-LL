# 1 "C:\\Users\\goldf\\OneDrive\\pc-sync\\SEGGER Embedded Studio for ARM Projects\\G431CBU6\\foc\\clarke.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 382 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Users\\goldf\\OneDrive\\pc-sync\\SEGGER Embedded Studio for ARM Projects\\G431CBU6\\foc\\clarke.c" 2
# 43 "C:\\Users\\goldf\\OneDrive\\pc-sync\\SEGGER Embedded Studio for ARM Projects\\G431CBU6\\foc\\clarke.c"
# 1 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/foc/clarke.h" 1
# 14 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/foc/clarke.h"
# 1 "C:/Users/goldf/AppData/Local/SEGGER/SEGGER Embedded Studio/v3/packages/libraries/libcxx/include\\math.h" 1
# 294 "C:/Users/goldf/AppData/Local/SEGGER/SEGGER Embedded Studio/v3/packages/libraries/libcxx/include\\math.h"
# 1 "C:/Users/goldf/AppData/Local/SEGGER/SEGGER Embedded Studio/v3/packages/libraries/libcxx/include\\__config" 1
# 21 "C:/Users/goldf/AppData/Local/SEGGER/SEGGER Embedded Studio/v3/packages/libraries/libcxx/include\\__config" 3
# 295 "C:/Users/goldf/AppData/Local/SEGGER/SEGGER Embedded Studio/v3/packages/libraries/libcxx/include\\math.h" 2
# 298 "C:/Users/goldf/AppData/Local/SEGGER/SEGGER Embedded Studio/v3/packages/libraries/libcxx/include\\math.h" 3



# 1 "C:/Users/goldf/AppData/Local/SEGGER/SEGGER Embedded Studio/v3/packages/libraries/libcxx/include\\stdlib.h" 1 3
# 14 "C:/Users/goldf/AppData/Local/SEGGER/SEGGER Embedded Studio/v3/packages/libraries/libcxx/include\\stdlib.h" 3






# 1 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include\\stdlib.h" 1 3
# 20 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include\\stdlib.h" 3
# 1 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL.h" 1 3
# 17 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL.h" 3
# 1 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL_ConfDefaults.h" 1 3
# 13 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL_ConfDefaults.h" 3
# 1 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL_Conf.h" 1 3
# 25 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL_Conf.h" 3
# 1 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL_Arm_Conf.h" 1 3
# 476 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL_Arm_Conf.h" 3
  static __inline__ __attribute__((__always_inline__)) int __SEGGER_RTL_CLZ_U32_safe_inline(unsigned x) {
    return x == 0 ? 32 : __builtin_clz(x);
  }
# 667 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL_Arm_Conf.h" 3
static __inline__ __attribute__((__always_inline__)) void __SEGGER_RTL_WR_PARTIAL_WORD_func(char *addr, unsigned w, int n) {
  switch (n) {
  default: addr[3] = (-1) > 0 ? w : w >> 24;
  case 3: addr[2] = (-1) > 0 ? w >> 8 : w >> 16;
  case 2: addr[1] = (-1) > 0 ? w >> 16 : w >> 8;
  case 1: addr[0] = (-1) > 0 ? w >> 24 : w;
  case 0: ;
  }
}

static __inline__ __attribute__((__always_inline__)) void __SEGGER_RTL_WR_WORD_func(char *addr, unsigned w) {
  __SEGGER_RTL_WR_PARTIAL_WORD_func(addr, w, 4);
}

static __inline__ __attribute__((__always_inline__)) unsigned __SEGGER_RTL_RD_WORD_func(const void *addr) {
  const unsigned char *pAddr = (const unsigned char *)addr;

  return pAddr[0] * ((-1) > 0 ? 0x1000000u : 0x1u) +
         pAddr[1] * ((-1) > 0 ? 0x10000u : 0x100u) +
         pAddr[2] * ((-1) > 0 ? 0x100u : 0x10000u) +
         pAddr[3] * ((-1) > 0 ? 0x1u : 0x1000000u);
}

static __inline__ __attribute__((__always_inline__)) unsigned __SEGGER_RTL_BYTE_PATTERN_func(unsigned x) {
  return x * 0x01010101uL;
}

static __inline__ __attribute__((__always_inline__)) unsigned __SEGGER_RTL_FILL_HEAD_func(const void *pOrigin, unsigned Word, unsigned Standin) {
  unsigned Mask;
  unsigned Fill;

  (void)pOrigin;

  Fill = __SEGGER_RTL_BYTE_PATTERN_func(Standin);
# 711 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL_Arm_Conf.h" 3
  Mask = 0xFFFFFFFFu;
  Mask <<= 8 * 0;

  return (Word & Mask) | (Fill & ~Mask);


}

static __inline__ __attribute__((__always_inline__)) unsigned __SEGGER_RTL_FILL_TAIL_func(unsigned n, unsigned Word, unsigned Standin) {
  unsigned Mask;
  unsigned Fill;
# 736 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL_Arm_Conf.h" 3
  if (n >= 4) {
    return Word;
  } else {
    Fill = __SEGGER_RTL_BYTE_PATTERN_func(Standin);
    Mask = 0xFFFFFFFFu << (8 * n);

    return (Fill & Mask) | (Word & ~Mask);
  }


}

static __inline__ __attribute__((__always_inline__)) unsigned __SEGGER_RTL_ZBYTE_CHECK_func(unsigned x) {



  return __builtin_arm_uqsub8(0x01010101, x);






}

static __inline__ __attribute__((__always_inline__)) unsigned __SEGGER_RTL_DIFF_INDEX_func(unsigned x, unsigned y) {



  return __SEGGER_RTL_CLZ_U32_safe_inline(__builtin_arm_rbit(x^y)) / 8;
# 792 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL_Arm_Conf.h" 3
}

static __inline__ __attribute__((__always_inline__)) unsigned __SEGGER_RTL_DIFF_BYTE_func(unsigned x, int Index) {



  return (x >> (8*Index)) & 0xFF;

}

static __inline__ __attribute__((__always_inline__)) unsigned __SEGGER_RTL_ZBYTE_INDEX_func(unsigned x) {







  return __SEGGER_RTL_CLZ_U32_safe_inline(__builtin_arm_rbit(__SEGGER_RTL_ZBYTE_CHECK_func(x))) / 8;
# 845 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL_Arm_Conf.h" 3
}
# 856 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL_Arm_Conf.h" 3
extern const int __aeabi_SIGABRT;
extern const int __aeabi_SIGINT;
extern const int __aeabi_SIGILL;
extern const int __aeabi_SIGFPE;
extern const int __aeabi_SIGSEGV;
extern const int __aeabi_SIGTERM;

void __aeabi_SIG_DFL(int sig);
void __aeabi_SIG_IGN(int sig);
void __aeabi_SIG_ERR(int sig);
# 26 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL_Conf.h" 2 3
# 14 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL_ConfDefaults.h" 2 3
# 18 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL.h" 2 3
# 38 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL.h" 3
  typedef struct __SEGGER_RTL_FILE_impl __SEGGER_RTL_FILE;




typedef struct __SEGGER_RTL_locale_data_s __SEGGER_RTL_locale_t;
typedef struct __SEGGER_RTL_locale_codeset_s __SEGGER_RTL_locale_codeset_t;

typedef struct {



  const char * decimal_point;
  const char * thousands_sep;
  const char * grouping;

  const char * int_curr_symbol;
  const char * currency_symbol;
  const char * mon_decimal_point;
  const char * mon_thousands_sep;
  const char * mon_grouping;
  const char * positive_sign;
  const char * negative_sign;

  char int_frac_digits;
  char frac_digits;
  char p_cs_precedes;
  char p_sep_by_space;
  char n_cs_precedes;
  char n_sep_by_space;
  char p_sign_posn;
  char n_sign_posn;
  char int_p_cs_precedes;
  char int_n_cs_precedes;
  char int_p_sep_by_space;
  char int_n_sep_by_space;
  char int_p_sign_posn;
  char int_n_sign_posn;




  const char *day_names;
  const char *abbrev_day_names;
  const char *month_names;
  const char *abbrev_month_names;
  const char *am_pm_indicator;
  const char *date_format;
  const char *time_format;
  const char *date_time_format;
} __SEGGER_RTL_locale_data_t;

struct __SEGGER_RTL_locale_data_s {
  const char * name;
  const __SEGGER_RTL_locale_data_t * data;
  const __SEGGER_RTL_locale_codeset_t * codeset;
};

struct __SEGGER_RTL_POSIX_locale_s {
  const __SEGGER_RTL_locale_t *__category[5];
};

struct timeval;
# 109 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL.h" 3
extern struct __SEGGER_RTL_POSIX_locale_s __SEGGER_RTL_global_locale;
extern struct __SEGGER_RTL_POSIX_locale_s * __SEGGER_RTL_locale_ptr;
extern char * __SEGGER_RTL_locale_name_buffer;
# 120 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL.h" 3
extern const __SEGGER_RTL_locale_t __SEGGER_RTL_c_locale;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_1;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_2;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_3;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_4;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_5;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_6;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_7;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_8;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_9;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_10;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_11;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_13;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_14;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_15;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_16;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1250;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1251;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1252;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1253;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1254;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1255;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1256;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1257;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1258;

extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_c_locale_data;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_aa_DJ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_aa_ER_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_aa_ET_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_af_NA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_af_ZA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ak_GH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_am_ET_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_AE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_BH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_DZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_EG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_IQ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_JO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_KW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_LB_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_LY_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_MA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_OM_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_QA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_SA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_SD_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_SY_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_TN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_YE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_as_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_asa_TZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_az_Arab_IR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_az_AZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_az_Cyrl_AZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_az_IR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_az_Latn_AZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_be_BY_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_bem_ZM_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_bez_TZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_bg_BG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_bm_ML_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_bn_BD_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_bn_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_bo_CN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_bo_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_br_FR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_brx_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_bs_BA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_byn_ER_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ca_ES_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_cch_NG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_cgg_UG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_chr_US_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_cs_CZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_cy_GB_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_da_DK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_dav_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_de_AT_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_de_BE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_de_CH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_de_DE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_de_LI_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_de_LU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_dv_MV_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_dz_BT_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ebu_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ee_GH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ee_TG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_el_CY_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_el_GR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_AS_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_AU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_BE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_BW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_BZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_CA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_Dsrt_US_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_GB_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_GU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_HK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_IE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_JM_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_MH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_MP_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_MT_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_MU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_NA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_NZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_PH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_PK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_SG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_TT_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_UM_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_US_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_US_POSIX_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_VI_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_ZA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_ZW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_ZZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_AR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_BO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_CL_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_CO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_CR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_DO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_EC_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_ES_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_GQ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_GT_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_HN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_MX_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_NI_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_PA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_PE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_PR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_PY_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_SV_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_US_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_UY_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_VE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_et_EE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_eu_ES_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fa_AF_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fa_IR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ff_SN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fi_FI_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fil_PH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fo_FO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_BE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_BF_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_BI_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_BJ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_BL_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_CA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_CD_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_CF_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_CG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_CH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_CI_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_CM_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_DJ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_FR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_GA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_GN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_GP_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_GQ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_KM_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_LU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_MC_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_MF_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_MG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_ML_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_MQ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_NE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_RE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_RW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_SN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_TD_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_TG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fur_IT_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ga_IE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_gaa_GH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_gez_ER_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_gez_ET_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_gl_ES_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_gsw_CH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_gu_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_guz_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_gv_GB_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ha_Arab_NG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ha_Arab_SD_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ha_GH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ha_Latn_GH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ha_Latn_NE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ha_Latn_NG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ha_NE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ha_NG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ha_SD_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_haw_US_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_he_IL_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_hi_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_hr_HR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_hu_HU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_hy_AM_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_id_ID_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ig_NG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ii_CN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_is_IS_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_it_CH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_it_IT_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ja_JP_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_jmc_TZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ka_GE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kab_DZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kaj_NG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kam_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kcg_NG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kde_TZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kea_CV_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kfo_CI_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_khq_ML_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ki_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kk_Cyrl_KZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kk_KZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kl_GL_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kln_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_km_KH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kn_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ko_KR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kok_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kpe_GN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kpe_LR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ksb_TZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ksh_DE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ku_Arab_IQ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ku_Arab_IR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ku_IQ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ku_IR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ku_Latn_SY_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ku_Latn_TR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ku_SY_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ku_TR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kw_GB_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ky_KG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_lag_TZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_lg_UG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ln_CD_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ln_CG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_lo_LA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_lt_LT_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_luo_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_luy_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_lv_LV_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mas_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mas_TZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mer_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mfe_MU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mg_MG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mi_NZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mk_MK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ml_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mn_CN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mn_Cyrl_MN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mn_MN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mn_Mong_CN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mr_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ms_BN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ms_MY_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mt_MT_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_my_MM_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_naq_NA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_nb_NO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_nd_ZW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_nds_DE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ne_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ne_NP_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_nl_BE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_nl_NL_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_nn_NO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_nr_ZA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_nso_ZA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ny_MW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_nyn_UG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_oc_FR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_om_ET_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_om_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_or_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_pa_Arab_PK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_pa_Guru_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_pa_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_pa_PK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_pl_PL_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ps_AF_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_pt_AO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_pt_BR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_pt_GW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_pt_MZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_pt_PT_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_rm_CH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ro_MD_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ro_RO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_rof_TZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ru_MD_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ru_RU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ru_UA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_rw_RW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_rwk_TZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sa_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_saq_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_se_FI_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_se_NO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_seh_MZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ses_ML_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sg_CF_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sh_BA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sh_CS_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sh_YU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_shi_Latn_MA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_shi_MA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_shi_Tfng_MA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_si_LK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sid_ET_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sk_SK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sl_SI_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sn_ZW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_so_DJ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_so_ET_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_so_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_so_SO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sq_AL_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_BA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_CS_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_Cyrl_BA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_Cyrl_CS_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_Cyrl_ME_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_Cyrl_RS_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_Cyrl_YU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_Latn_BA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_Latn_CS_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_Latn_ME_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_Latn_RS_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_Latn_YU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_ME_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_RS_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_YU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ss_SZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ss_ZA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ssy_ER_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_st_LS_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_st_ZA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sv_FI_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sv_SE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sw_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sw_TZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_syr_SY_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ta_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ta_LK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_te_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_teo_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_teo_UG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_tg_Cyrl_TJ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_tg_TJ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_th_TH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ti_ER_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ti_ET_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_tig_ER_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_tl_PH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_tn_ZA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_to_TO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_tr_TR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_trv_TW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ts_ZA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_tt_RU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_tzm_Latn_MA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_tzm_MA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ug_Arab_CN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ug_CN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_uk_UA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ur_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ur_PK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_uz_AF_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_uz_Arab_AF_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_uz_Cyrl_UZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_uz_Latn_UZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_uz_UZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ve_ZA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_vi_VN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_vun_TZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_wal_ET_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_wo_Latn_SN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_wo_SN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_xh_ZA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_xog_UG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_yo_NG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_CN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_Hans_CN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_Hans_HK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_Hans_MO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_Hans_SG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_Hant_HK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_Hant_MO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_Hant_TW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_HK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_MO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_SG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_TW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zu_ZA_locale;

extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_ascii;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_utf8;

extern const char __SEGGER_RTL_data_utf8_period [];
extern const char __SEGGER_RTL_data_utf8_comma [];
extern const char __SEGGER_RTL_data_utf8_space [];
extern const char __SEGGER_RTL_data_utf8_plus [];
extern const char __SEGGER_RTL_data_utf8_minus [];
extern const char __SEGGER_RTL_data_empty_string[];
# 548 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL.h" 3
int __SEGGER_RTL_X_set_time_of_day (const struct timeval *__tp);
int __SEGGER_RTL_X_get_time_of_day (struct timeval *__tp);
const __SEGGER_RTL_locale_t * __SEGGER_RTL_X_find_locale (const char *__locale);
__SEGGER_RTL_FILE * __SEGGER_RTL_X_file_open (const char *__filename, const char *__mode);
int __SEGGER_RTL_X_file_stat (__SEGGER_RTL_FILE *__stream);
int __SEGGER_RTL_X_file_read (__SEGGER_RTL_FILE *__stream, char *__s, unsigned __len);
int __SEGGER_RTL_X_file_write (__SEGGER_RTL_FILE *__stream, const char *__s, unsigned __len);
int __SEGGER_RTL_X_file_unget (__SEGGER_RTL_FILE *__stream, int __c);
int __SEGGER_RTL_X_file_close (__SEGGER_RTL_FILE *__stream);
int __SEGGER_RTL_X_file_error (__SEGGER_RTL_FILE *__stream);
int __SEGGER_RTL_X_file_flush (__SEGGER_RTL_FILE *__stream);
int __SEGGER_RTL_X_file_eof (__SEGGER_RTL_FILE *__stream);
void __SEGGER_RTL_X_file_clrerr (__SEGGER_RTL_FILE *__stream);
int __SEGGER_RTL_X_file_seek (__SEGGER_RTL_FILE *__stream, long __offset, int __whence);
int __SEGGER_RTL_X_file_getpos (__SEGGER_RTL_FILE *__stream, long *__pos);
int __SEGGER_RTL_X_file_bufsize (__SEGGER_RTL_FILE *__stream);
__SEGGER_RTL_FILE * __SEGGER_RTL_X_file_tmpfile (void);
char * __SEGGER_RTL_X_file_tmpnam (char *__s, unsigned __max);
int __SEGGER_RTL_X_file_remove (const char *__filename);
int __SEGGER_RTL_X_file_rename (const char *__old, const char *__new);
void __attribute__((__weak__)) __SEGGER_RTL_X_heap_lock (void);
void __attribute__((__weak__)) __SEGGER_RTL_X_heap_unlock (void);
volatile int * __aeabi_errno_addr (void);
void __aeabi_assert (const char *__expression, const char *__filename, int __line);
# 580 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL.h" 3
void __SEGGER_RTL_execute_at_exit_fns (void);
void __SEGGER_RTL_set_locale_name_buffer (char *__buffer);
int __SEGGER_RTL_mb_max (const struct __SEGGER_RTL_POSIX_locale_s *__loc);
int __SEGGER_RTL_mb_cur_max (void);
# 21 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include\\stdlib.h" 2 3
# 39 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include\\stdlib.h" 3
typedef unsigned int size_t;




typedef unsigned int wchar_t;




typedef struct __SEGGER_RTL_POSIX_locale_s *locale_t;
# 64 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include\\stdlib.h" 3
typedef struct {
  int quot;
  int rem;
} div_t;

typedef struct {
  long quot;
  long rem;
} ldiv_t;

typedef struct {
  long long quot;
  long rem;
} lldiv_t;
# 86 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include\\stdlib.h" 3
int abs (int __j);
long int labs (long int __j);
long long int llabs (long long int __j);
div_t div (int __numer, int __denom);
ldiv_t ldiv (long int __numer, long int __denom);
lldiv_t lldiv (long long int __numer, long long int __denom);
void * malloc (size_t __size);
void * aligned_alloc (size_t alignment, size_t __size);
void * calloc (size_t __nobj, size_t __size);
void * realloc (void *__p, size_t __size);
void free (void *__p);
double atof (const char *__nptr);
double strtod (const char *__nptr, char **__endptr);
float strtof (const char *__nptr, char **__endptr);
long double strtold (const char *__nptr, char **__endptr);
int atoi (const char *__nptr);
long int atol (const char *__nptr);
long long int atoll (const char *__nptr);
long int strtol (const char *__nptr, char **__endptr, int __base);
long long int strtoll (const char *__nptr, char **__endptr, int __base);
unsigned long int strtoul (const char *__nptr, char **__endptr, int __base);
unsigned long long int strtoull (const char *__nptr, char **__endptr, int __base);
int rand (void);
void srand (unsigned int __seed);
void * bsearch (const void *__key, const void *__buf, size_t __num, size_t __size, int (*__compare)(const void *, const void *));
void qsort (void *__buf, size_t __num, size_t __size, int (*__compare)(const void *, const void *));
int atexit (void (*__func)(void));
char * getenv (const char *__name);
int system (const char *__command);
char * itoa (int __val, char *__buf, int __radix);
char * utoa (unsigned val, char *buf, int radix);
char * ltoa (long __val, char *__buf, int __radix);
char * ultoa (unsigned long __val, char *__buf, int __radix);
char * lltoa (long long __val, char *__buf, int __radix);
char * ulltoa (unsigned long long __val, char *__buf, int __radix);
int mblen (const char *__s, size_t __n);
int mblen_l (const char *__s, size_t __n, locale_t __loc);
size_t mbstowcs (wchar_t *__pwcs, const char *__s, size_t __n);
size_t mbstowcs_l (wchar_t *__pwcs, const char *__s, size_t __n, locale_t __loc);
int mbtowc (wchar_t *__pwc, const char *__s, size_t __n);
int mbtowc_l (wchar_t *__pwc, const char *__s, size_t __n, locale_t __loc);
int wctomb (char *__s, wchar_t __wc);
int wctomb_l (char *__s, wchar_t __wc, locale_t __loc);
size_t wcstombs (char *__s, const wchar_t *__pwcs, size_t __n);
size_t wcstombs_l (char *__s, const wchar_t *__pwcs, size_t __n, locale_t __loc);

                       void abort (void);
                       void exit (int __exit_code);
                       void _Exit (int __exit_code);
# 21 "C:/Users/goldf/AppData/Local/SEGGER/SEGGER Embedded Studio/v3/packages/libraries/libcxx/include\\stdlib.h" 2 3
# 302 "C:/Users/goldf/AppData/Local/SEGGER/SEGGER Embedded Studio/v3/packages/libraries/libcxx/include\\math.h" 2 3

# 1 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include\\math.h" 1 3
# 20 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include\\math.h" 3
# 1 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL_FP.h" 1 3
# 68 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL_FP.h" 3
float sinf (float __x);
double sin (double __x);
float cosf (float __x);
double cos (double __x);
float tanf (float __x);
double tan (double __x);
float asinf (float __x);
double asin (double __x);
float acosf (float __x);
double acos (double __x);
float atanf (float __x);
double atan (double __x);
float atan2f (float __y, float __x);
double atan2 (double __y, double __x);
float frexpf (float __x, int *__exp);
double frexp (double __x, int *__exp);
float ldexpf (float __x, int __exp);
double ldexp (double __x, int __exp);
float scalbnf (float __x, int __exp);
double scalbn (double __x, int __exp);
float logf (float __x);
double log (double __x);
float log1pf (float __x);
double log1p (double __x);
float log10f (float __x);
double log10 (double __x);
float log2f (float __x);
double log2 (double __x);
int ilogbf (float __x);
int ilogb (double __x);
float fmodf (float __x, float __y);
double fmod (double __x, double __y);
float modff (float __x, float *__iptr);
double modf (double __x, double *__iptr);
float powf (float __x, float __y);
double pow (double __x, double __y);
float sqrtf (float __x);
double sqrt (double __x);
float cbrtf (float __x);
double cbrt (double __x);
float rsqrtf (float __x);
double rsqrt (double __x);
float ceilf (float __x);
double ceil (double __x);
float fabsf (float __x);
double fabs (double __x);
float fminf (float __x, float __y);
double fmin (double __x, double __y);
float fmaxf (float __x, float __y);
double fmax (double __x, double __y);
float floorf (float __x);
double floor (double __x);
float hypotf (float __x, float __y);
double hypot (double __x, double __y);
float sinhf (float __x);
double sinh (double __x);
float coshf (float __x);
double cosh (double __x);
float tanhf (float __x);
double tanh (double __x);
float acoshf (float __x);
double acosh (double __x);
float asinhf (float __x);
double asinh (double __x);
float atanhf (float __x);
double atanh (double __x);
float fmaf (float __x, float __y, float __z);
double fma (double __x, double __y, double __z);
float expf (float __x);
double exp (double __x);
float exp2f (float __x);
double exp2 (double __x);
float exp10f (float __x);
double exp10 (double __x);
# 405 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL_FP.h" 3
unsigned __aeabi_fadd (unsigned, unsigned);
unsigned __aeabi_fsub (unsigned, unsigned);
unsigned __aeabi_frsub (unsigned, unsigned);
unsigned __aeabi_fmul (unsigned, unsigned);
unsigned __aeabi_fdiv (unsigned, unsigned);
int __aeabi_fcmplt (unsigned, unsigned);
int __aeabi_fcmple (unsigned, unsigned);
int __aeabi_fcmpgt (unsigned, unsigned);
int __aeabi_fcmpge (unsigned, unsigned);
int __aeabi_fcmpeq (unsigned, unsigned);
unsigned long long __aeabi_dadd (unsigned long long, unsigned long long);
unsigned long long __aeabi_dsub (unsigned long long, unsigned long long);
unsigned long long __aeabi_drsub (unsigned long long, unsigned long long);
unsigned long long __aeabi_dmul (unsigned long long, unsigned long long);
unsigned long long __aeabi_ddiv (unsigned long long, unsigned long long);
int __aeabi_dcmplt (unsigned long long, unsigned long long);
int __aeabi_dcmple (unsigned long long, unsigned long long);
int __aeabi_dcmpgt (unsigned long long, unsigned long long);
int __aeabi_dcmpge (unsigned long long, unsigned long long);
int __aeabi_dcmpeq (unsigned long long, unsigned long long);
int __aeabi_f2iz (unsigned);
unsigned __aeabi_f2uiz (unsigned);
long long __aeabi_f2lz (unsigned);
unsigned long long __aeabi_f2ulz (unsigned);
unsigned __aeabi_i2f (int);
unsigned __aeabi_ui2f (unsigned);
unsigned __aeabi_l2f (long long);
unsigned __aeabi_ul2f (unsigned long long);
int __aeabi_d2iz (unsigned long long);
long long __aeabi_d2lz (unsigned long long);
unsigned __aeabi_d2uiz (unsigned long long);
unsigned long long __aeabi_d2ulz (unsigned long long);
unsigned long long __aeabi_i2d (int);
unsigned long long __aeabi_ui2d (unsigned);
unsigned long long __aeabi_l2d (long long);
unsigned long long __aeabi_ul2d (unsigned long long);
unsigned long long __aeabi_f2d (unsigned);
unsigned __aeabi_d2f (unsigned long long);
unsigned short __aeabi_f2h (unsigned);
unsigned short __aeabi_d2h (unsigned long long);
unsigned __aeabi_h2f (unsigned short);
unsigned long long __aeabi_h2d (unsigned short);
# 457 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include/__SEGGER_RTL_FP.h" 3
int __SEGGER_RTL_float32_isinf (float);
int __SEGGER_RTL_float64_isinf (double);
int __SEGGER_RTL_float32_isnan (float);
int __SEGGER_RTL_float64_isnan (double);
int __SEGGER_RTL_float32_isfinite (float);
int __SEGGER_RTL_float64_isfinite (double);
int __SEGGER_RTL_float32_isnormal (float);
int __SEGGER_RTL_float64_isnormal (double);
int __SEGGER_RTL_float32_signbit (float);
int __SEGGER_RTL_float64_signbit (double);
int __SEGGER_RTL_float32_classify (float);
int __SEGGER_RTL_float64_classify (double);





typedef struct {
  float Re;
  float Im;
} __SEGGER_RTL_FLOAT32_PSEUDO_COMPLEX;

typedef struct {
  union {
    __SEGGER_RTL_FLOAT32_PSEUDO_COMPLEX part;

    float _Complex value;

  } u;
} __SEGGER_RTL_FLOAT32_COMPLEX;

typedef struct {
  double Re;
  double Im;
} __SEGGER_RTL_FLOAT64_PSEUDO_COMPLEX;

typedef struct {
  union {
    __SEGGER_RTL_FLOAT64_PSEUDO_COMPLEX part;

    double _Complex value;

  } u;
} __SEGGER_RTL_FLOAT64_COMPLEX;

typedef struct {
  long double Re;
  long double Im;
} __SEGGER_RTL_LDOUBLE_PSEUDO_COMPLEX;

typedef struct {
  union {
    __SEGGER_RTL_LDOUBLE_PSEUDO_COMPLEX part;

    long double _Complex value;

  } u;
} __SEGGER_RTL_LDOUBLE_COMPLEX;
# 21 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include\\math.h" 2 3
# 88 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include\\math.h" 3
typedef float float_t;
typedef double double_t;
# 98 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include\\math.h" 3
int __SEGGER_RTL_float32_isinf (float);
int __SEGGER_RTL_float64_isinf (double);
int __SEGGER_RTL_float32_isnan (float);
int __SEGGER_RTL_float64_isnan (double);
int __SEGGER_RTL_float32_isfinite (float);
int __SEGGER_RTL_float64_isfinite (double);
int __SEGGER_RTL_float32_isnormal (float);
int __SEGGER_RTL_float64_isnormal (double);
int __SEGGER_RTL_float32_signbit (float);
int __SEGGER_RTL_float64_signbit (double);
int __SEGGER_RTL_float32_classify (float);
int __SEGGER_RTL_float64_classify (double);
# 122 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include\\math.h" 3
float cosf (float __x);
float sinf (float __x);
float tanf (float __x);
float asinf (float __x);
float acosf (float __x);
float atanf (float __x);
float atan2f (float __y, float __x);
void sincosf (float __x, float *pSin, float *pCos);





float sinhf (float __x);
float coshf (float __x);
float tanhf (float __x);
float acoshf (float __x);
float asinhf (float __x);
float atanhf (float __x);





float logf (float __x);
float log2f (float __x);
float log10f (float __x);
float logbf (float __x);
float log1pf (float __x);
int ilogbf (float __x);
float expf (float __x);
float exp2f (float __x);
float exp10f (float __x);
float expm1f (float __x);
float sqrtf (float __x);
float cbrtf (float __x);
float rsqrtf (float __x);
float hypotf (float __x, float __y);
float powf (float __x, float __y);





float fminf (float __x, float __y);
float fmaxf (float __x, float __y);
float fdimf (float __x, float __y);
float fabsf (float __x);





float tgammaf (float __x);
float lgammaf (float __x);
float erff (float __x);
float erfcf (float __x);





float ceilf (float __x);
float floorf (float __x);
float truncf (float __x);
float rintf (float __x);
long lrintf (float __x);
long long llrintf (float __x);
float roundf (float __x);
long lroundf (float __x);
long long llroundf (float __x);
float nearbyintf (float __x);





float fmodf (float __x, float __y);
float remainderf (float __x, float __y);
float remquof (float __x, float __y, int *__quo);
float modff (float __x, float *__iptr);
float frexpf (float __x, int *__exp);
float ldexpf (float __x, int __exp);
float scalbnf (float __x, int __exp);
float scalblnf (float __x, long __exp);
float copysignf (float __x, float __y);
float nextafterf (float __x, float __y);
float nexttowardf(float __x, long double __y);
float nanf (const char *__tag);
# 223 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include\\math.h" 3
double sin (double __x);
double cos (double __x);
double tan (double __x);
double asin (double __x);
double acos (double __x);
double atan (double __x);
double atan2 (double __y, double __x);
void sincos (double __x, double *pSin, double *pCos);





double sinh (double __x);
double cosh (double __x);
double tanh (double __x);
double asinh (double __x);
double acosh (double __x);
double atanh (double __x);





double log (double __x);
double log2 (double __x);
double log10 (double __x);
double logb (double __x);
double log1p (double __x);
int ilogb (double __x);
double exp (double __x);
double exp2 (double __x);
double exp10 (double __x);
double expm1 (double __x);
double sqrt (double __x);
double cbrt (double __x);
double rsqrt (double __x);
double hypot (double __x, double __y);
double pow (double __x, double __y);





double fmin (double __x, double __y);
double fmax (double __x, double __y);
double fdim (double __x, double __y);
double fabs (double __x);





double tgamma (double __x);
double lgamma (double __x);
double erf (double __x);
double erfc (double __x);





double ceil (double __x);
double floor (double __x);
double trunc (double __x);
double rint (double __x);
long lrint (double __x);
long long llrint (double __x);
double round (double __x);
long lround (double __x);
long long llround (double __x);
double nearbyint (double __x);





double fmod (double __x, double __y);
double remainder (double __x, double __y);
double remquo (double __x, double __y, int *__quo);
double modf (double __x, double *__iptr);
double frexp (double __x, int *__exp);
double ldexp (double __x, int __exp);
double scalbn (double __x, int __exp);
double scalbln (double __x, long __exp);
double copysign (double __x, double __y);
double nextafter (double __x, double __y);
double nexttoward (double __x, long double __y);
double nan (const char *__tag);
# 324 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include\\math.h" 3
long double sinl (long double __x);
long double cosl (long double __x);
long double tanl (long double __x);
long double asinl (long double __x);
long double acosl (long double __x);
long double atanl (long double __x);
long double atan2l (long double __y, long double __x);
void sincosl (long double __x, long double *pSin, long double *pCos);





long double sinhl (long double __x);
long double coshl (long double __x);
long double tanhl (long double __x);
long double asinhl (long double __x);
long double acoshl (long double __x);
long double atanhl (long double __x);





long double logl (long double __x);
long double log2l (long double __x);
long double log10l (long double __x);
long double logbl (long double __x);
long double log1pl (long double __x);
int ilogbl (long double __x);
long double expl (long double __x);
long double exp2l (long double __x);
long double exp10l (long double __x);
long double expm1l (long double __x);
long double sqrtl (long double __x);
long double cbrtl (long double __x);
long double rsqrtl (long double __x);
long double hypotl (long double __x, long double __y);
long double powl (long double __x, long double __y);





long double fminl (long double __x, long double __y);
long double fmaxl (long double __x, long double __y);
long double fdiml (long double __x, long double __y);
long double fabsl (long double __x);





long double tgammal (long double __x);
long double lgammal (long double __x);
long double erfl (long double __x);
long double erfcl (long double __x);





long double ceill (long double __x);
long double floorl (long double __x);
long double truncl (long double __x);
long double rintl (long double __x);
long lrintl (long double __x);
long long llrintl (long double __x);
long double roundl (long double __x);
long lroundl (long double __x);
long long llroundl (long double __x);
long double nearbyintl (long double __x);





long double fmodl (long double __x, long double __y);
long double remainderl (long double __x, long double __y);
long double remquol (long double __x, long double __y, int *__quo);
long double modfl (long double __x, long double *__iptr);
long double frexpl (long double __x, int *__exp);
long double ldexpl (long double __x, int __exp);
long double scalbnl (long double __x, int __exp);
long double scalblnl (long double __x, long __exp);
long double copysignl (long double __x, long double __y);
long double nextafterl (long double __x, long double __y);
long double nexttowardl(long double __x, long double __y);
long double nanl (const char *__tag);

float fmaf (float __x, float __y, float __z);
double fma (double __x, double __y, double __z);
long double fmal (long double __x, long double __y, long double __z);
# 304 "C:/Users/goldf/AppData/Local/SEGGER/SEGGER Embedded Studio/v3/packages/libraries/libcxx/include\\math.h" 2 3
# 15 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/foc/clarke.h" 2
# 1 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6\\utils.h" 1
# 19 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6\\utils.h"
# 1 "C:/Users/goldf/AppData/Local/SEGGER/SEGGER Embedded Studio/v3/packages/libraries/libcxx/include\\math.h" 1
# 20 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6\\utils.h" 2
# 1 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/CMSIS/Device/Include\\stm32g4xx.h" 1
# 108 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/CMSIS/Device/Include\\stm32g4xx.h"
# 1 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/CMSIS/Device/Include/stm32g431xx.h" 1
# 66 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/CMSIS/Device/Include/stm32g431xx.h"
typedef enum
{

  NonMaskableInt_IRQn = -14,
  HardFault_IRQn = -13,
  MemoryManagement_IRQn = -12,
  BusFault_IRQn = -11,
  UsageFault_IRQn = -10,
  SVCall_IRQn = -5,
  DebugMonitor_IRQn = -4,
  PendSV_IRQn = -2,
  SysTick_IRQn = -1,

  WWDG_IRQn = 0,
  PVD_PVM_IRQn = 1,
  RTC_TAMP_LSECSS_IRQn = 2,
  RTC_WKUP_IRQn = 3,
  FLASH_IRQn = 4,
  RCC_IRQn = 5,
  EXTI0_IRQn = 6,
  EXTI1_IRQn = 7,
  EXTI2_IRQn = 8,
  EXTI3_IRQn = 9,
  EXTI4_IRQn = 10,
  DMA1_Channel1_IRQn = 11,
  DMA1_Channel2_IRQn = 12,
  DMA1_Channel3_IRQn = 13,
  DMA1_Channel4_IRQn = 14,
  DMA1_Channel5_IRQn = 15,
  DMA1_Channel6_IRQn = 16,
  ADC1_2_IRQn = 18,
  USB_HP_IRQn = 19,
  USB_LP_IRQn = 20,
  FDCAN1_IT0_IRQn = 21,
  FDCAN1_IT1_IRQn = 22,
  EXTI9_5_IRQn = 23,
  TIM1_BRK_TIM15_IRQn = 24,
  TIM1_UP_TIM16_IRQn = 25,
  TIM1_TRG_COM_TIM17_IRQn = 26,
  TIM1_CC_IRQn = 27,
  TIM2_IRQn = 28,
  TIM3_IRQn = 29,
  TIM4_IRQn = 30,
  I2C1_EV_IRQn = 31,
  I2C1_ER_IRQn = 32,
  I2C2_EV_IRQn = 33,
  I2C2_ER_IRQn = 34,
  SPI1_IRQn = 35,
  SPI2_IRQn = 36,
  USART1_IRQn = 37,
  USART2_IRQn = 38,
  USART3_IRQn = 39,
  EXTI15_10_IRQn = 40,
  RTC_Alarm_IRQn = 41,
  USBWakeUp_IRQn = 42,
  TIM8_BRK_IRQn = 43,
  TIM8_UP_IRQn = 44,
  TIM8_TRG_COM_IRQn = 45,
  TIM8_CC_IRQn = 46,
  LPTIM1_IRQn = 49,
  SPI3_IRQn = 51,
  UART4_IRQn = 52,
  TIM6_DAC_IRQn = 54,
  TIM7_IRQn = 55,
  DMA2_Channel1_IRQn = 56,
  DMA2_Channel2_IRQn = 57,
  DMA2_Channel3_IRQn = 58,
  DMA2_Channel4_IRQn = 59,
  DMA2_Channel5_IRQn = 60,
  UCPD1_IRQn = 63,
  COMP1_2_3_IRQn = 64,
  COMP4_IRQn = 65,
  CRS_IRQn = 75,
  SAI1_IRQn = 76,
  FPU_IRQn = 81,
  RNG_IRQn = 90,
  LPUART1_IRQn = 91,
  I2C3_EV_IRQn = 92,
  I2C3_ER_IRQn = 93,
  DMAMUX_OVR_IRQn = 94,
  DMA2_Channel6_IRQn = 97,
  CORDIC_IRQn = 100,
  FMAC_IRQn = 101
} IRQn_Type;





# 1 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 1
# 29 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3





# 1 "C:/Users/goldf/AppData/Local/SEGGER/SEGGER Embedded Studio/v3/packages/libraries/libcxx/include\\stdint.h" 1 3
# 110 "C:/Users/goldf/AppData/Local/SEGGER/SEGGER Embedded Studio/v3/packages/libraries/libcxx/include\\stdint.h" 3
# 123 "C:/Users/goldf/AppData/Local/SEGGER/SEGGER Embedded Studio/v3/packages/libraries/libcxx/include\\stdint.h" 3
# 1 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include\\stdint.h" 1 3
# 213 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 6.30/include\\stdint.h" 3
typedef signed char int8_t;
typedef unsigned char uint8_t;

typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;

typedef signed long long int64_t;
typedef unsigned long long uint64_t;

typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;

typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;

typedef int32_t int_fast8_t;
typedef int32_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef int64_t int_fast64_t;

typedef uint32_t uint_fast8_t;
typedef uint32_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef uint64_t uint_fast64_t;


typedef int32_t intptr_t;
typedef uint32_t uintptr_t;





typedef int64_t intmax_t;
typedef uint64_t uintmax_t;
# 124 "C:/Users/goldf/AppData/Local/SEGGER/SEGGER Embedded Studio/v3/packages/libraries/libcxx/include\\stdint.h" 2 3
# 35 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 2 3
# 63 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
# 1 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_version.h" 1 3
# 29 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_version.h" 3
# 64 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 2 3
# 162 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
# 1 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_compiler.h" 1 3
# 54 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_compiler.h" 3
# 1 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 1 3
# 29 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wunused-parameter"
# 71 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpacked"
#pragma GCC diagnostic ignored "-Wattributes"
  struct __attribute__((packed)) T_UINT32 { uint32_t v; };
#pragma GCC diagnostic pop



#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpacked"
#pragma GCC diagnostic ignored "-Wattributes"
  struct __attribute__((packed, aligned(1))) T_UINT16_WRITE { uint16_t v; };
#pragma GCC diagnostic pop



#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpacked"
#pragma GCC diagnostic ignored "-Wattributes"
  struct __attribute__((packed, aligned(1))) T_UINT16_READ { uint16_t v; };
#pragma GCC diagnostic pop



#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpacked"
#pragma GCC diagnostic ignored "-Wattributes"
  struct __attribute__((packed, aligned(1))) T_UINT32_WRITE { uint32_t v; };
#pragma GCC diagnostic pop



#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpacked"
#pragma GCC diagnostic ignored "-Wattributes"
  struct __attribute__((packed, aligned(1))) T_UINT32_READ { uint32_t v; };
#pragma GCC diagnostic pop
# 131 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline __attribute__((__noreturn__)) void __cmsis_start(void)
{
  extern void _start(void) __attribute__((__noreturn__));

  typedef struct {
    uint32_t const* src;
    uint32_t* dest;
    uint32_t wlen;
  } __copy_table_t;

  typedef struct {
    uint32_t* dest;
    uint32_t wlen;
  } __zero_table_t;

  extern const __copy_table_t __copy_table_start__;
  extern const __copy_table_t __copy_table_end__;
  extern const __zero_table_t __zero_table_start__;
  extern const __zero_table_t __zero_table_end__;

  for (__copy_table_t const* pTable = &__copy_table_start__; pTable < &__copy_table_end__; ++pTable) {
    for(uint32_t i=0u; i<pTable->wlen; ++i) {
      pTable->dest[i] = pTable->src[i];
    }
  }

  for (__zero_table_t const* pTable = &__zero_table_start__; pTable < &__zero_table_end__; ++pTable) {
    for(uint32_t i=0u; i<pTable->wlen; ++i) {
      pTable->dest[i] = 0u;
    }
  }

  _start();
}
# 196 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline void __enable_irq(void)
{
  __asm volatile ("cpsie i" : : : "memory");
}







__attribute__((always_inline)) static inline void __disable_irq(void)
{
  __asm volatile ("cpsid i" : : : "memory");
}







__attribute__((always_inline)) static inline uint32_t __get_CONTROL(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, control" : "=r" (result) );
  return(result);
}
# 248 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline void __set_CONTROL(uint32_t control)
{
  __asm volatile ("MSR control, %0" : : "r" (control) : "memory");
}
# 272 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __get_IPSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, ipsr" : "=r" (result) );
  return(result);
}







__attribute__((always_inline)) static inline uint32_t __get_APSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, apsr" : "=r" (result) );
  return(result);
}







__attribute__((always_inline)) static inline uint32_t __get_xPSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, xpsr" : "=r" (result) );
  return(result);
}







__attribute__((always_inline)) static inline uint32_t __get_PSP(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, psp" : "=r" (result) );
  return(result);
}
# 344 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline void __set_PSP(uint32_t topOfProcStack)
{
  __asm volatile ("MSR psp, %0" : : "r" (topOfProcStack) : );
}
# 368 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __get_MSP(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, msp" : "=r" (result) );
  return(result);
}
# 398 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline void __set_MSP(uint32_t topOfMainStack)
{
  __asm volatile ("MSR msp, %0" : : "r" (topOfMainStack) : );
}
# 449 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __get_PRIMASK(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, primask" : "=r" (result) );
  return(result);
}
# 479 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline void __set_PRIMASK(uint32_t priMask)
{
  __asm volatile ("MSR primask, %0" : : "r" (priMask) : "memory");
}
# 506 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline void __enable_fault_irq(void)
{
  __asm volatile ("cpsie f" : : : "memory");
}







__attribute__((always_inline)) static inline void __disable_fault_irq(void)
{
  __asm volatile ("cpsid f" : : : "memory");
}







__attribute__((always_inline)) static inline uint32_t __get_BASEPRI(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, basepri" : "=r" (result) );
  return(result);
}
# 558 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline void __set_BASEPRI(uint32_t basePri)
{
  __asm volatile ("MSR basepri, %0" : : "r" (basePri) : "memory");
}
# 583 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline void __set_BASEPRI_MAX(uint32_t basePri)
{
  __asm volatile ("MSR basepri_max, %0" : : "r" (basePri) : "memory");
}







__attribute__((always_inline)) static inline uint32_t __get_FAULTMASK(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, faultmask" : "=r" (result) );
  return(result);
}
# 624 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline void __set_FAULTMASK(uint32_t faultMask)
{
  __asm volatile ("MSR faultmask, %0" : : "r" (faultMask) : "memory");
}
# 833 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __get_FPSCR(void)
{






  return __builtin_arm_get_fpscr();
# 851 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
}







__attribute__((always_inline)) static inline void __set_FPSCR(uint32_t fpscr)
{






  __builtin_arm_set_fpscr(fpscr);






}
# 933 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline void __ISB(void)
{
  __asm volatile ("isb 0xF":::"memory");
}







__attribute__((always_inline)) static inline void __DSB(void)
{
  __asm volatile ("dsb 0xF":::"memory");
}







__attribute__((always_inline)) static inline void __DMB(void)
{
  __asm volatile ("dmb 0xF":::"memory");
}
# 967 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __REV(uint32_t value)
{



  uint32_t result;

  __asm ("rev %0, %1" : "=r" (result) : "r" (value) );
  return result;

}
# 986 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __REV16(uint32_t value)
{
  uint32_t result;

  __asm ("rev16 %0, %1" : "=r" (result) : "r" (value) );
  return result;
}
# 1001 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline int16_t __REVSH(int16_t value)
{



  int16_t result;

  __asm ("revsh %0, %1" : "=r" (result) : "r" (value) );
  return result;

}
# 1021 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __ROR(uint32_t op1, uint32_t op2)
{
  op2 %= 32U;
  if (op2 == 0U)
  {
    return op1;
  }
  return (op1 >> op2) | (op1 << (32U - op2));
}
# 1048 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __RBIT(uint32_t value)
{
  uint32_t result;




   __asm ("rbit %0, %1" : "=r" (result) : "r" (value) );
# 1068 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
  return result;
}
# 1078 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint8_t __CLZ(uint32_t value)
{
# 1089 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
  if (value == 0U)
  {
    return 32U;
  }
  return __builtin_clz(value);
}
# 1107 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint8_t __LDREXB(volatile uint8_t *addr)
{
    uint32_t result;







   __asm volatile ("ldrexb %0, [%1]" : "=r" (result) : "r" (addr) : "memory" );

   return ((uint8_t) result);
}
# 1129 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint16_t __LDREXH(volatile uint16_t *addr)
{
    uint32_t result;







   __asm volatile ("ldrexh %0, [%1]" : "=r" (result) : "r" (addr) : "memory" );

   return ((uint16_t) result);
}
# 1151 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __LDREXW(volatile uint32_t *addr)
{
    uint32_t result;

   __asm volatile ("ldrex %0, %1" : "=r" (result) : "Q" (*addr) );
   return(result);
}
# 1168 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __STREXB(uint8_t value, volatile uint8_t *addr)
{
   uint32_t result;

   __asm volatile ("strexb %0, %2, %1" : "=&r" (result), "=Q" (*addr) : "r" ((uint32_t)value) );
   return(result);
}
# 1185 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __STREXH(uint16_t value, volatile uint16_t *addr)
{
   uint32_t result;

   __asm volatile ("strexh %0, %2, %1" : "=&r" (result), "=Q" (*addr) : "r" ((uint32_t)value) );
   return(result);
}
# 1202 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __STREXW(uint32_t value, volatile uint32_t *addr)
{
   uint32_t result;

   __asm volatile ("strex %0, %2, %1" : "=&r" (result), "=Q" (*addr) : "r" (value) );
   return(result);
}






__attribute__((always_inline)) static inline void __CLREX(void)
{
  __asm volatile ("clrex" ::: "memory");
}
# 1268 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __RRX(uint32_t value)
{
  uint32_t result;

  __asm volatile ("rrx %0, %1" : "=r" (result) : "r" (value) );
  return(result);
}
# 1283 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint8_t __LDRBT(volatile uint8_t *ptr)
{
    uint32_t result;







   __asm volatile ("ldrbt %0, [%1]" : "=r" (result) : "r" (ptr) : "memory" );

   return ((uint8_t) result);
}
# 1305 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint16_t __LDRHT(volatile uint16_t *ptr)
{
    uint32_t result;







   __asm volatile ("ldrht %0, [%1]" : "=r" (result) : "r" (ptr) : "memory" );

   return ((uint16_t) result);
}
# 1327 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __LDRT(volatile uint32_t *ptr)
{
    uint32_t result;

   __asm volatile ("ldrt %0, %1" : "=r" (result) : "Q" (*ptr) );
   return(result);
}
# 1342 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline void __STRBT(uint8_t value, volatile uint8_t *ptr)
{
   __asm volatile ("strbt %1, %0" : "=Q" (*ptr) : "r" ((uint32_t)value) );
}
# 1354 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline void __STRHT(uint16_t value, volatile uint16_t *ptr)
{
   __asm volatile ("strht %1, %0" : "=Q" (*ptr) : "r" ((uint32_t)value) );
}
# 1366 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline void __STRT(uint32_t value, volatile uint32_t *ptr)
{
   __asm volatile ("strt %1, %0" : "=Q" (*ptr) : "r" (value) );
}
# 1621 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __SADD8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("sadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __QADD8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("qadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SHADD8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("shadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UADD8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UQADD8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("uqadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UHADD8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("uhadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}


__attribute__((always_inline)) static inline uint32_t __SSUB8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("ssub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __QSUB8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("qsub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SHSUB8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("shsub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __USUB8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("usub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UQSUB8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("uqsub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UHSUB8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("uhsub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}


__attribute__((always_inline)) static inline uint32_t __SADD16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("sadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __QADD16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("qadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SHADD16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("shadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UADD16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UQADD16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("uqadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UHADD16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("uhadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SSUB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("ssub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __QSUB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("qsub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SHSUB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("shsub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __USUB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("usub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UQSUB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("uqsub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UHSUB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("uhsub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SASX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("sasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __QASX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("qasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SHASX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("shasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UASX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UQASX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("uqasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UHASX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("uhasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SSAX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("ssax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __QSAX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("qsax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SHSAX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("shsax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __USAX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("usax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UQSAX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("uqsax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UHSAX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("uhsax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __USAD8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("usad8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __USADA8(uint32_t op1, uint32_t op2, uint32_t op3)
{
  uint32_t result;

  __asm ("usada8 %0, %1, %2, %3" : "=r" (result) : "r" (op1), "r" (op2), "r" (op3) );
  return(result);
}
# 1941 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __UXTB16(uint32_t op1)
{
  uint32_t result;

  __asm ("uxtb16 %0, %1" : "=r" (result) : "r" (op1));
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UXTAB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("uxtab16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SXTB16(uint32_t op1)
{
  uint32_t result;

  __asm ("sxtb16 %0, %1" : "=r" (result) : "r" (op1));
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SXTB16_RORn(uint32_t op1, uint32_t rotate)
{
  uint32_t result;

  __asm ("sxtb16 %0, %1, ROR %2" : "=r" (result) : "r" (op1), "i" (rotate) );

  return result;
}

__attribute__((always_inline)) static inline uint32_t __SXTAB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm ("sxtab16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SMUAD (uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("smuad %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SMUADX (uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("smuadx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SMLAD (uint32_t op1, uint32_t op2, uint32_t op3)
{
  uint32_t result;

  __asm volatile ("smlad %0, %1, %2, %3" : "=r" (result) : "r" (op1), "r" (op2), "r" (op3) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SMLADX (uint32_t op1, uint32_t op2, uint32_t op3)
{
  uint32_t result;

  __asm volatile ("smladx %0, %1, %2, %3" : "=r" (result) : "r" (op1), "r" (op2), "r" (op3) );
  return(result);
}

__attribute__((always_inline)) static inline uint64_t __SMLALD (uint32_t op1, uint32_t op2, uint64_t acc)
{
  union llreg_u{
    uint32_t w32[2];
    uint64_t w64;
  } llr;
  llr.w64 = acc;


  __asm volatile ("smlald %0, %1, %2, %3" : "=r" (llr.w32[0]), "=r" (llr.w32[1]): "r" (op1), "r" (op2) , "0" (llr.w32[0]), "1" (llr.w32[1]) );




  return(llr.w64);
}

__attribute__((always_inline)) static inline uint64_t __SMLALDX (uint32_t op1, uint32_t op2, uint64_t acc)
{
  union llreg_u{
    uint32_t w32[2];
    uint64_t w64;
  } llr;
  llr.w64 = acc;


  __asm volatile ("smlaldx %0, %1, %2, %3" : "=r" (llr.w32[0]), "=r" (llr.w32[1]): "r" (op1), "r" (op2) , "0" (llr.w32[0]), "1" (llr.w32[1]) );




  return(llr.w64);
}

__attribute__((always_inline)) static inline uint32_t __SMUSD (uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("smusd %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SMUSDX (uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("smusdx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SMLSD (uint32_t op1, uint32_t op2, uint32_t op3)
{
  uint32_t result;

  __asm volatile ("smlsd %0, %1, %2, %3" : "=r" (result) : "r" (op1), "r" (op2), "r" (op3) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SMLSDX (uint32_t op1, uint32_t op2, uint32_t op3)
{
  uint32_t result;

  __asm volatile ("smlsdx %0, %1, %2, %3" : "=r" (result) : "r" (op1), "r" (op2), "r" (op3) );
  return(result);
}

__attribute__((always_inline)) static inline uint64_t __SMLSLD (uint32_t op1, uint32_t op2, uint64_t acc)
{
  union llreg_u{
    uint32_t w32[2];
    uint64_t w64;
  } llr;
  llr.w64 = acc;


  __asm volatile ("smlsld %0, %1, %2, %3" : "=r" (llr.w32[0]), "=r" (llr.w32[1]): "r" (op1), "r" (op2) , "0" (llr.w32[0]), "1" (llr.w32[1]) );




  return(llr.w64);
}

__attribute__((always_inline)) static inline uint64_t __SMLSLDX (uint32_t op1, uint32_t op2, uint64_t acc)
{
  union llreg_u{
    uint32_t w32[2];
    uint64_t w64;
  } llr;
  llr.w64 = acc;


  __asm volatile ("smlsldx %0, %1, %2, %3" : "=r" (llr.w32[0]), "=r" (llr.w32[1]): "r" (op1), "r" (op2) , "0" (llr.w32[0]), "1" (llr.w32[1]) );




  return(llr.w64);
}

__attribute__((always_inline)) static inline uint32_t __SEL (uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("sel %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline int32_t __QADD( int32_t op1, int32_t op2)
{
  int32_t result;

  __asm volatile ("qadd %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline int32_t __QSUB( int32_t op1, int32_t op2)
{
  int32_t result;

  __asm volatile ("qsub %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}
# 2163 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline int32_t __SMMLA (int32_t op1, int32_t op2, int32_t op3)
{
 int32_t result;

 __asm ("smmla %0, %1, %2, %3" : "=r" (result): "r" (op1), "r" (op2), "r" (op3) );
 return(result);
}





#pragma GCC diagnostic pop
# 55 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/cmsis_compiler.h" 2 3
# 163 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 2 3
# 264 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
typedef union
{
  struct
  {
    uint32_t _reserved0:16;
    uint32_t GE:4;
    uint32_t _reserved1:7;
    uint32_t Q:1;
    uint32_t V:1;
    uint32_t C:1;
    uint32_t Z:1;
    uint32_t N:1;
  } b;
  uint32_t w;
} APSR_Type;
# 303 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
typedef union
{
  struct
  {
    uint32_t ISR:9;
    uint32_t _reserved0:23;
  } b;
  uint32_t w;
} IPSR_Type;
# 321 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
typedef union
{
  struct
  {
    uint32_t ISR:9;
    uint32_t _reserved0:1;
    uint32_t ICI_IT_1:6;
    uint32_t GE:4;
    uint32_t _reserved1:4;
    uint32_t T:1;
    uint32_t ICI_IT_2:2;
    uint32_t Q:1;
    uint32_t V:1;
    uint32_t C:1;
    uint32_t Z:1;
    uint32_t N:1;
  } b;
  uint32_t w;
} xPSR_Type;
# 376 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
typedef union
{
  struct
  {
    uint32_t nPRIV:1;
    uint32_t SPSEL:1;
    uint32_t FPCA:1;
    uint32_t _reserved0:29;
  } b;
  uint32_t w;
} CONTROL_Type;
# 411 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
typedef struct
{
  volatile uint32_t ISER[8U];
        uint32_t RESERVED0[24U];
  volatile uint32_t ICER[8U];
        uint32_t RESERVED1[24U];
  volatile uint32_t ISPR[8U];
        uint32_t RESERVED2[24U];
  volatile uint32_t ICPR[8U];
        uint32_t RESERVED3[24U];
  volatile uint32_t IABR[8U];
        uint32_t RESERVED4[56U];
  volatile uint8_t IP[240U];
        uint32_t RESERVED5[644U];
  volatile uint32_t STIR;
} NVIC_Type;
# 445 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
typedef struct
{
  volatile const uint32_t CPUID;
  volatile uint32_t ICSR;
  volatile uint32_t VTOR;
  volatile uint32_t AIRCR;
  volatile uint32_t SCR;
  volatile uint32_t CCR;
  volatile uint8_t SHP[12U];
  volatile uint32_t SHCSR;
  volatile uint32_t CFSR;
  volatile uint32_t HFSR;
  volatile uint32_t DFSR;
  volatile uint32_t MMFAR;
  volatile uint32_t BFAR;
  volatile uint32_t AFSR;
  volatile const uint32_t PFR[2U];
  volatile const uint32_t DFR;
  volatile const uint32_t ADR;
  volatile const uint32_t MMFR[4U];
  volatile const uint32_t ISAR[5U];
        uint32_t RESERVED0[5U];
  volatile uint32_t CPACR;
} SCB_Type;
# 724 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
typedef struct
{
        uint32_t RESERVED0[1U];
  volatile const uint32_t ICTR;
  volatile uint32_t ACTLR;
} SCnSCB_Type;
# 764 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
typedef struct
{
  volatile uint32_t CTRL;
  volatile uint32_t LOAD;
  volatile uint32_t VAL;
  volatile const uint32_t CALIB;
} SysTick_Type;
# 816 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
typedef struct
{
  volatile union
  {
    volatile uint8_t u8;
    volatile uint16_t u16;
    volatile uint32_t u32;
  } PORT [32U];
        uint32_t RESERVED0[864U];
  volatile uint32_t TER;
        uint32_t RESERVED1[15U];
  volatile uint32_t TPR;
        uint32_t RESERVED2[15U];
  volatile uint32_t TCR;
        uint32_t RESERVED3[32U];
        uint32_t RESERVED4[43U];
  volatile uint32_t LAR;
  volatile const uint32_t LSR;
        uint32_t RESERVED5[6U];
  volatile const uint32_t PID4;
  volatile const uint32_t PID5;
  volatile const uint32_t PID6;
  volatile const uint32_t PID7;
  volatile const uint32_t PID0;
  volatile const uint32_t PID1;
  volatile const uint32_t PID2;
  volatile const uint32_t PID3;
  volatile const uint32_t CID0;
  volatile const uint32_t CID1;
  volatile const uint32_t CID2;
  volatile const uint32_t CID3;
} ITM_Type;
# 904 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
typedef struct
{
  volatile uint32_t CTRL;
  volatile uint32_t CYCCNT;
  volatile uint32_t CPICNT;
  volatile uint32_t EXCCNT;
  volatile uint32_t SLEEPCNT;
  volatile uint32_t LSUCNT;
  volatile uint32_t FOLDCNT;
  volatile const uint32_t PCSR;
  volatile uint32_t COMP0;
  volatile uint32_t MASK0;
  volatile uint32_t FUNCTION0;
        uint32_t RESERVED0[1U];
  volatile uint32_t COMP1;
  volatile uint32_t MASK1;
  volatile uint32_t FUNCTION1;
        uint32_t RESERVED1[1U];
  volatile uint32_t COMP2;
  volatile uint32_t MASK2;
  volatile uint32_t FUNCTION2;
        uint32_t RESERVED2[1U];
  volatile uint32_t COMP3;
  volatile uint32_t MASK3;
  volatile uint32_t FUNCTION3;
} DWT_Type;
# 1051 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
typedef struct
{
  volatile const uint32_t SSPSR;
  volatile uint32_t CSPSR;
        uint32_t RESERVED0[2U];
  volatile uint32_t ACPR;
        uint32_t RESERVED1[55U];
  volatile uint32_t SPPR;
        uint32_t RESERVED2[131U];
  volatile const uint32_t FFSR;
  volatile uint32_t FFCR;
  volatile const uint32_t FSCR;
        uint32_t RESERVED3[759U];
  volatile const uint32_t TRIGGER;
  volatile const uint32_t FIFO0;
  volatile const uint32_t ITATBCTR2;
        uint32_t RESERVED4[1U];
  volatile const uint32_t ITATBCTR0;
  volatile const uint32_t FIFO1;
  volatile uint32_t ITCTRL;
        uint32_t RESERVED5[39U];
  volatile uint32_t CLAIMSET;
  volatile uint32_t CLAIMCLR;
        uint32_t RESERVED7[8U];
  volatile const uint32_t DEVID;
  volatile const uint32_t DEVTYPE;
} TPI_Type;
# 1213 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
typedef struct
{
  volatile const uint32_t TYPE;
  volatile uint32_t CTRL;
  volatile uint32_t RNR;
  volatile uint32_t RBAR;
  volatile uint32_t RASR;
  volatile uint32_t RBAR_A1;
  volatile uint32_t RASR_A1;
  volatile uint32_t RBAR_A2;
  volatile uint32_t RASR_A2;
  volatile uint32_t RBAR_A3;
  volatile uint32_t RASR_A3;
} MPU_Type;
# 1309 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
typedef struct
{
        uint32_t RESERVED0[1U];
  volatile uint32_t FPCCR;
  volatile uint32_t FPCAR;
  volatile uint32_t FPDSCR;
  volatile const uint32_t MVFR0;
  volatile const uint32_t MVFR1;
  volatile const uint32_t MVFR2;
} FPU_Type;
# 1421 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
typedef struct
{
  volatile uint32_t DHCSR;
  volatile uint32_t DCRSR;
  volatile uint32_t DCRDR;
  volatile uint32_t DEMCR;
} CoreDebug_Type;
# 1653 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
static inline void __NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);

  reg_value = ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR;
  reg_value &= ~((uint32_t)((0xFFFFUL << 16U) | (7UL << 8U)));
  reg_value = (reg_value |
                ((uint32_t)0x5FAUL << 16U) |
                (PriorityGroupTmp << 8U) );
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR = reg_value;
}







static inline uint32_t __NVIC_GetPriorityGrouping(void)
{
  return ((uint32_t)((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) >> 8U));
}
# 1684 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
static inline void __NVIC_EnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    __asm volatile("":::"memory");
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
    __asm volatile("":::"memory");
  }
}
# 1703 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
static inline uint32_t __NVIC_GetEnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}
# 1722 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
static inline void __NVIC_DisableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
    __DSB();
    __ISB();
  }
}
# 1741 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
static inline uint32_t __NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}
# 1760 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
static inline void __NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
  }
}
# 1775 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
static inline void __NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
  }
}
# 1792 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
static inline uint32_t __NVIC_GetActive(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IABR[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}
# 1814 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
static inline void __NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)IRQn)] = (uint8_t)((priority << (8U - 4)) & (uint32_t)0xFFUL);
  }
  else
  {
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)IRQn) & 0xFUL)-4UL] = (uint8_t)((priority << (8U - 4)) & (uint32_t)0xFFUL);
  }
}
# 1836 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
static inline uint32_t __NVIC_GetPriority(IRQn_Type IRQn)
{

  if ((int32_t)(IRQn) >= 0)
  {
    return(((uint32_t)((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)IRQn)] >> (8U - 4)));
  }
  else
  {
    return(((uint32_t)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)IRQn) & 0xFUL)-4UL] >> (8U - 4)));
  }
}
# 1861 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
static inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(4)) ? (uint32_t)(4) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits = ((PriorityGroupTmp + (uint32_t)(4)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(4));

  return (
           ((PreemptPriority & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
           ((SubPriority & (uint32_t)((1UL << (SubPriorityBits )) - 1UL)))
         );
}
# 1888 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
static inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* const pPreemptPriority, uint32_t* const pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(4)) ? (uint32_t)(4) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits = ((PriorityGroupTmp + (uint32_t)(4)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(4));

  *pPreemptPriority = (Priority >> SubPriorityBits) & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL);
  *pSubPriority = (Priority ) & (uint32_t)((1UL << (SubPriorityBits )) - 1UL);
}
# 1911 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
static inline void __NVIC_SetVector(IRQn_Type IRQn, uint32_t vector)
{
  uint32_t *vectors = (uint32_t *)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->VTOR;
  vectors[(int32_t)IRQn + 16] = vector;

}
# 1927 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
static inline uint32_t __NVIC_GetVector(IRQn_Type IRQn)
{
  uint32_t *vectors = (uint32_t *)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->VTOR;
  return vectors[(int32_t)IRQn + 16];
}






__attribute__((__noreturn__)) static inline void __NVIC_SystemReset(void)
{
  __DSB();

  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR = (uint32_t)((0x5FAUL << 16U) |
                           (((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) |
                            (1UL << 2U) );
  __DSB();

  for(;;)
  {
    __asm volatile ("nop");
  }
}
# 1960 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
# 1 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/mpu_armv7.h" 1 3
# 29 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/mpu_armv7.h" 3
# 183 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include/mpu_armv7.h" 3
typedef struct {
  uint32_t RBAR;
  uint32_t RASR;
} ARM_MPU_Region_t;




static inline void ARM_MPU_Enable(uint32_t MPU_Control)
{
  __DMB();
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->CTRL = MPU_Control | (1UL );

  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHCSR |= (1UL << 16U);

  __DSB();
  __ISB();
}



static inline void ARM_MPU_Disable(void)
{
  __DMB();

  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHCSR &= ~(1UL << 16U);

  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->CTRL &= ~(1UL );
  __DSB();
  __ISB();
}




static inline void ARM_MPU_ClrRegion(uint32_t rnr)
{
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RNR = rnr;
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RASR = 0U;
}





static inline void ARM_MPU_SetRegion(uint32_t rbar, uint32_t rasr)
{
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RBAR = rbar;
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RASR = rasr;
}






static inline void ARM_MPU_SetRegionEx(uint32_t rnr, uint32_t rbar, uint32_t rasr)
{
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RNR = rnr;
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RBAR = rbar;
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RASR = rasr;
}






static inline void ARM_MPU_OrderedMemcpy(volatile uint32_t* dst, const uint32_t* __restrict src, uint32_t len)
{
  uint32_t i;
  for (i = 0U; i < len; ++i)
  {
    dst[i] = src[i];
  }
}





static inline void ARM_MPU_Load(ARM_MPU_Region_t const* table, uint32_t cnt)
{
  const uint32_t rowWordSize = sizeof(ARM_MPU_Region_t)/4U;
  while (cnt > 4U) {
    ARM_MPU_OrderedMemcpy(&(((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RBAR), &(table->RBAR), 4U*rowWordSize);
    table += 4U;
    cnt -= 4U;
  }
  ARM_MPU_OrderedMemcpy(&(((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RBAR), &(table->RBAR), cnt*rowWordSize);
}
# 1961 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 2 3
# 1981 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
static inline uint32_t SCB_GetFPUType(void)
{
  uint32_t mvfr0;

  mvfr0 = ((FPU_Type *) ((0xE000E000UL) + 0x0F30UL) )->MVFR0;
  if ((mvfr0 & ((0xFUL << 4U) | (0xFUL << 8U))) == 0x020U)
  {
    return 1U;
  }
  else
  {
    return 0U;
  }
}
# 2022 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
static inline uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1UL) > (0xFFFFFFUL ))
  {
    return (1UL);
  }

  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD = (uint32_t)(ticks - 1UL);
  __NVIC_SetPriority (SysTick_IRQn, (1UL << 4) - 1UL);
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL = 0UL;
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL = (1UL << 2U) |
                   (1UL << 1U) |
                   (1UL );
  return (0UL);
}
# 2052 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
extern volatile int32_t ITM_RxBuffer;
# 2064 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
static inline uint32_t ITM_SendChar (uint32_t ch)
{
  if (((((ITM_Type *) (0xE0000000UL) )->TCR & (1UL )) != 0UL) &&
      ((((ITM_Type *) (0xE0000000UL) )->TER & 1UL ) != 0UL) )
  {
    while (((ITM_Type *) (0xE0000000UL) )->PORT[0U].u32 == 0UL)
    {
      __asm volatile ("nop");
    }
    ((ITM_Type *) (0xE0000000UL) )->PORT[0U].u8 = (uint8_t)ch;
  }
  return (ch);
}
# 2085 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
static inline int32_t ITM_ReceiveChar (void)
{
  int32_t ch = -1;

  if (ITM_RxBuffer != ((int32_t)0x5AA55AA5U))
  {
    ch = ITM_RxBuffer;
    ITM_RxBuffer = ((int32_t)0x5AA55AA5U);
  }

  return (ch);
}
# 2105 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/CMSIS_5/CMSIS/Core/Include\\core_cm4.h" 3
static inline int32_t ITM_CheckChar (void)
{

  if (ITM_RxBuffer == ((int32_t)0x5AA55AA5U))
  {
    return (0);
  }
  else
  {
    return (1);
  }
}
# 156 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/CMSIS/Device/Include/stm32g431xx.h" 2
# 1 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/CMSIS/Device/Include/system_stm32g4xx.h" 1
# 58 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/CMSIS/Device/Include/system_stm32g4xx.h"
extern uint32_t SystemCoreClock;

extern const uint8_t AHBPrescTable[16];
extern const uint8_t APBPrescTable[8];
# 87 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/CMSIS/Device/Include/system_stm32g4xx.h"
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);
# 157 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/CMSIS/Device/Include/stm32g431xx.h" 2
# 167 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/CMSIS/Device/Include/stm32g431xx.h"
typedef struct
{
  volatile uint32_t ISR;
  volatile uint32_t IER;
  volatile uint32_t CR;
  volatile uint32_t CFGR;
  volatile uint32_t CFGR2;
  volatile uint32_t SMPR1;
  volatile uint32_t SMPR2;
       uint32_t RESERVED1;
  volatile uint32_t TR1;
  volatile uint32_t TR2;
  volatile uint32_t TR3;
       uint32_t RESERVED2;
  volatile uint32_t SQR1;
  volatile uint32_t SQR2;
  volatile uint32_t SQR3;
  volatile uint32_t SQR4;
  volatile uint32_t DR;
       uint32_t RESERVED3;
       uint32_t RESERVED4;
  volatile uint32_t JSQR;
       uint32_t RESERVED5[4];
  volatile uint32_t OFR1;
  volatile uint32_t OFR2;
  volatile uint32_t OFR3;
  volatile uint32_t OFR4;
       uint32_t RESERVED6[4];
  volatile uint32_t JDR1;
  volatile uint32_t JDR2;
  volatile uint32_t JDR3;
  volatile uint32_t JDR4;
       uint32_t RESERVED7[4];
  volatile uint32_t AWD2CR;
  volatile uint32_t AWD3CR;
       uint32_t RESERVED8;
       uint32_t RESERVED9;
  volatile uint32_t DIFSEL;
  volatile uint32_t CALFACT;
       uint32_t RESERVED10[2];
  volatile uint32_t GCOMP;
} ADC_TypeDef;

typedef struct
{
  volatile uint32_t CSR;
  uint32_t RESERVED1;
  volatile uint32_t CCR;
  volatile uint32_t CDR;
} ADC_Common_TypeDef;





typedef struct
{
  volatile uint32_t CREL;
  volatile uint32_t ENDN;
       uint32_t RESERVED1;
  volatile uint32_t DBTP;
  volatile uint32_t TEST;
  volatile uint32_t RWD;
  volatile uint32_t CCCR;
  volatile uint32_t NBTP;
  volatile uint32_t TSCC;
  volatile uint32_t TSCV;
  volatile uint32_t TOCC;
  volatile uint32_t TOCV;
       uint32_t RESERVED2[4];
  volatile uint32_t ECR;
  volatile uint32_t PSR;
  volatile uint32_t TDCR;
       uint32_t RESERVED3;
  volatile uint32_t IR;
  volatile uint32_t IE;
  volatile uint32_t ILS;
  volatile uint32_t ILE;
       uint32_t RESERVED4[8];
  volatile uint32_t RXGFC;
  volatile uint32_t XIDAM;
  volatile uint32_t HPMS;
       uint32_t RESERVED5;
  volatile uint32_t RXF0S;
  volatile uint32_t RXF0A;
  volatile uint32_t RXF1S;
  volatile uint32_t RXF1A;
       uint32_t RESERVED6[8];
  volatile uint32_t TXBC;
  volatile uint32_t TXFQS;
  volatile uint32_t TXBRP;
  volatile uint32_t TXBAR;
  volatile uint32_t TXBCR;
  volatile uint32_t TXBTO;
  volatile uint32_t TXBCF;
  volatile uint32_t TXBTIE;
  volatile uint32_t TXBCIE;
  volatile uint32_t TXEFS;
  volatile uint32_t TXEFA;
} FDCAN_GlobalTypeDef;





typedef struct
{
  volatile uint32_t CKDIV;
} FDCAN_Config_TypeDef;





typedef struct
{
  volatile uint32_t CSR;
} COMP_TypeDef;





typedef struct
{
  volatile uint32_t DR;
  volatile uint32_t IDR;
  volatile uint32_t CR;
  uint32_t RESERVED0;
  volatile uint32_t INIT;
  volatile uint32_t POL;
} CRC_TypeDef;




typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFGR;
  volatile uint32_t ISR;
  volatile uint32_t ICR;
} CRS_TypeDef;





typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t SWTRIGR;
  volatile uint32_t DHR12R1;
  volatile uint32_t DHR12L1;
  volatile uint32_t DHR8R1;
  volatile uint32_t DHR12R2;
  volatile uint32_t DHR12L2;
  volatile uint32_t DHR8R2;
  volatile uint32_t DHR12RD;
  volatile uint32_t DHR12LD;
  volatile uint32_t DHR8RD;
  volatile uint32_t DOR1;
  volatile uint32_t DOR2;
  volatile uint32_t SR;
  volatile uint32_t CCR;
  volatile uint32_t MCR;
  volatile uint32_t SHSR1;
  volatile uint32_t SHSR2;
  volatile uint32_t SHHR;
  volatile uint32_t SHRR;
  volatile uint32_t RESERVED[2];
  volatile uint32_t STR1;
  volatile uint32_t STR2;
  volatile uint32_t STMODR;
} DAC_TypeDef;





typedef struct
{
  volatile uint32_t IDCODE;
  volatile uint32_t CR;
  volatile uint32_t APB1FZR1;
  volatile uint32_t APB1FZR2;
  volatile uint32_t APB2FZ;
} DBGMCU_TypeDef;





typedef struct
{
  volatile uint32_t CCR;
  volatile uint32_t CNDTR;
  volatile uint32_t CPAR;
  volatile uint32_t CMAR;
} DMA_Channel_TypeDef;

typedef struct
{
  volatile uint32_t ISR;
  volatile uint32_t IFCR;
} DMA_TypeDef;





typedef struct
{
  volatile uint32_t CCR;
}DMAMUX_Channel_TypeDef;

typedef struct
{
  volatile uint32_t CSR;
  volatile uint32_t CFR;
}DMAMUX_ChannelStatus_TypeDef;

typedef struct
{
  volatile uint32_t RGCR;
}DMAMUX_RequestGen_TypeDef;

typedef struct
{
  volatile uint32_t RGSR;
  volatile uint32_t RGCFR;
}DMAMUX_RequestGenStatus_TypeDef;





typedef struct
{
  volatile uint32_t IMR1;
  volatile uint32_t EMR1;
  volatile uint32_t RTSR1;
  volatile uint32_t FTSR1;
  volatile uint32_t SWIER1;
  volatile uint32_t PR1;
  uint32_t RESERVED1;
  uint32_t RESERVED2;
  volatile uint32_t IMR2;
  volatile uint32_t EMR2;
  volatile uint32_t RTSR2;
  volatile uint32_t FTSR2;
  volatile uint32_t SWIER2;
  volatile uint32_t PR2;
} EXTI_TypeDef;





typedef struct
{
  volatile uint32_t ACR;
  volatile uint32_t PDKEYR;
  volatile uint32_t KEYR;
  volatile uint32_t OPTKEYR;
  volatile uint32_t SR;
  volatile uint32_t CR;
  volatile uint32_t ECCR;
       uint32_t RESERVED1;
  volatile uint32_t OPTR;
  volatile uint32_t PCROP1SR;
  volatile uint32_t PCROP1ER;
  volatile uint32_t WRP1AR;
  volatile uint32_t WRP1BR;
       uint32_t RESERVED2[15];
  volatile uint32_t SEC1R;
} FLASH_TypeDef;




typedef struct
{
  volatile uint32_t X1BUFCFG;
  volatile uint32_t X2BUFCFG;
  volatile uint32_t YBUFCFG;
  volatile uint32_t PARAM;
  volatile uint32_t CR;
  volatile uint32_t SR;
  volatile uint32_t WDATA;
  volatile uint32_t RDATA;
} FMAC_TypeDef;






typedef struct
{
  volatile uint32_t MODER;
  volatile uint32_t OTYPER;
  volatile uint32_t OSPEEDR;
  volatile uint32_t PUPDR;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t LCKR;
  volatile uint32_t AFR[2];
  volatile uint32_t BRR;
} GPIO_TypeDef;





typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t OAR1;
  volatile uint32_t OAR2;
  volatile uint32_t TIMINGR;
  volatile uint32_t TIMEOUTR;
  volatile uint32_t ISR;
  volatile uint32_t ICR;
  volatile uint32_t PECR;
  volatile uint32_t RXDR;
  volatile uint32_t TXDR;
} I2C_TypeDef;





typedef struct
{
  volatile uint32_t KR;
  volatile uint32_t PR;
  volatile uint32_t RLR;
  volatile uint32_t SR;
  volatile uint32_t WINR;
} IWDG_TypeDef;





typedef struct
{
  volatile uint32_t ISR;
  volatile uint32_t ICR;
  volatile uint32_t IER;
  volatile uint32_t CFGR;
  volatile uint32_t CR;
  volatile uint32_t CMP;
  volatile uint32_t ARR;
  volatile uint32_t CNT;
  volatile uint32_t OR;
} LPTIM_TypeDef;





typedef struct
{
  volatile uint32_t CSR;
  volatile uint32_t RESERVED[5];
  volatile uint32_t TCMR;
} OPAMP_TypeDef;





typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t CR3;
  volatile uint32_t CR4;
  volatile uint32_t SR1;
  volatile uint32_t SR2;
  volatile uint32_t SCR;
  uint32_t RESERVED;
  volatile uint32_t PUCRA;
  volatile uint32_t PDCRA;
  volatile uint32_t PUCRB;
  volatile uint32_t PDCRB;
  volatile uint32_t PUCRC;
  volatile uint32_t PDCRC;
  volatile uint32_t PUCRD;
  volatile uint32_t PDCRD;
  volatile uint32_t PUCRE;
  volatile uint32_t PDCRE;
  volatile uint32_t PUCRF;
  volatile uint32_t PDCRF;
  volatile uint32_t PUCRG;
  volatile uint32_t PDCRG;
  uint32_t RESERVED1[10];
  volatile uint32_t CR5;
} PWR_TypeDef;






typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t ICSCR;
  volatile uint32_t CFGR;
  volatile uint32_t PLLCFGR;
  uint32_t RESERVED0;
  uint32_t RESERVED1;
  volatile uint32_t CIER;
  volatile uint32_t CIFR;
  volatile uint32_t CICR;
  uint32_t RESERVED2;
  volatile uint32_t AHB1RSTR;
  volatile uint32_t AHB2RSTR;
  volatile uint32_t AHB3RSTR;
  uint32_t RESERVED3;
  volatile uint32_t APB1RSTR1;
  volatile uint32_t APB1RSTR2;
  volatile uint32_t APB2RSTR;
  uint32_t RESERVED4;
  volatile uint32_t AHB1ENR;
  volatile uint32_t AHB2ENR;
  volatile uint32_t AHB3ENR;
  uint32_t RESERVED5;
  volatile uint32_t APB1ENR1;
  volatile uint32_t APB1ENR2;
  volatile uint32_t APB2ENR;
  uint32_t RESERVED6;
  volatile uint32_t AHB1SMENR;
  volatile uint32_t AHB2SMENR;
  volatile uint32_t AHB3SMENR;
  uint32_t RESERVED7;
  volatile uint32_t APB1SMENR1;
  volatile uint32_t APB1SMENR2;
  volatile uint32_t APB2SMENR;
  uint32_t RESERVED8;
  volatile uint32_t CCIPR;
  uint32_t RESERVED9;
  volatile uint32_t BDCR;
  volatile uint32_t CSR;
  volatile uint32_t CRRCR;
  volatile uint32_t CCIPR2;
} RCC_TypeDef;
# 633 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/CMSIS/Device/Include/stm32g431xx.h"
typedef struct
{
  volatile uint32_t TR;
  volatile uint32_t DR;
  volatile uint32_t SSR;
  volatile uint32_t ICSR;
  volatile uint32_t PRER;
  volatile uint32_t WUTR;
  volatile uint32_t CR;
       uint32_t RESERVED0;
       uint32_t RESERVED1;
  volatile uint32_t WPR;
  volatile uint32_t CALR;
  volatile uint32_t SHIFTR;
  volatile uint32_t TSTR;
  volatile uint32_t TSDR;
  volatile uint32_t TSSSR;
       uint32_t RESERVED2;
  volatile uint32_t ALRMAR;
  volatile uint32_t ALRMASSR;
  volatile uint32_t ALRMBR;
  volatile uint32_t ALRMBSSR;
  volatile uint32_t SR;
  volatile uint32_t MISR;
       uint32_t RESERVED3;
  volatile uint32_t SCR;
} RTC_TypeDef;





typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
       uint32_t RESERVED0;
  volatile uint32_t FLTCR;
       uint32_t RESERVED1[6];
       uint32_t RESERVED2;
  volatile uint32_t IER;
  volatile uint32_t SR;
  volatile uint32_t MISR;
       uint32_t RESERVED3;
  volatile uint32_t SCR;
       uint32_t RESERVED4[48];
  volatile uint32_t BKP0R;
  volatile uint32_t BKP1R;
  volatile uint32_t BKP2R;
  volatile uint32_t BKP3R;
  volatile uint32_t BKP4R;
  volatile uint32_t BKP5R;
  volatile uint32_t BKP6R;
  volatile uint32_t BKP7R;
  volatile uint32_t BKP8R;
  volatile uint32_t BKP9R;
  volatile uint32_t BKP10R;
  volatile uint32_t BKP11R;
  volatile uint32_t BKP12R;
  volatile uint32_t BKP13R;
  volatile uint32_t BKP14R;
  volatile uint32_t BKP15R;
} TAMP_TypeDef;





typedef struct
{
  volatile uint32_t GCR;
  uint32_t RESERVED[16];
  volatile uint32_t PDMCR;
  volatile uint32_t PDMDLY;
} SAI_TypeDef;

typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t FRCR;
  volatile uint32_t SLOTR;
  volatile uint32_t IMR;
  volatile uint32_t SR;
  volatile uint32_t CLRFR;
  volatile uint32_t DR;
} SAI_Block_TypeDef;





typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SR;
  volatile uint32_t DR;
  volatile uint32_t CRCPR;
  volatile uint32_t RXCRCR;
  volatile uint32_t TXCRCR;
  volatile uint32_t I2SCFGR;
  volatile uint32_t I2SPR;
} SPI_TypeDef;





typedef struct
{
  volatile uint32_t MEMRMP;
  volatile uint32_t CFGR1;
  volatile uint32_t EXTICR[4];
  volatile uint32_t SCSR;
  volatile uint32_t CFGR2;
  volatile uint32_t SWPR;
  volatile uint32_t SKR;
} SYSCFG_TypeDef;





typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SMCR;
  volatile uint32_t DIER;
  volatile uint32_t SR;
  volatile uint32_t EGR;
  volatile uint32_t CCMR1;
  volatile uint32_t CCMR2;
  volatile uint32_t CCER;
  volatile uint32_t CNT;
  volatile uint32_t PSC;
  volatile uint32_t ARR;
  volatile uint32_t RCR;
  volatile uint32_t CCR1;
  volatile uint32_t CCR2;
  volatile uint32_t CCR3;
  volatile uint32_t CCR4;
  volatile uint32_t BDTR;
  volatile uint32_t CCR5;
  volatile uint32_t CCR6;
  volatile uint32_t CCMR3;
  volatile uint32_t DTR2;
  volatile uint32_t ECR;
  volatile uint32_t TISEL;
  volatile uint32_t AF1;
  volatile uint32_t AF2;
  volatile uint32_t OR ;
       uint32_t RESERVED0[220];
  volatile uint32_t DCR;
  volatile uint32_t DMAR;
} TIM_TypeDef;




typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t CR3;
  volatile uint32_t BRR;
  volatile uint32_t GTPR;
  volatile uint32_t RTOR;
  volatile uint32_t RQR;
  volatile uint32_t ISR;
  volatile uint32_t ICR;
  volatile uint32_t RDR;
  volatile uint32_t TDR;
  volatile uint32_t PRESC;
} USART_TypeDef;





typedef struct
{
  volatile uint16_t EP0R;
  volatile uint16_t RESERVED0;
  volatile uint16_t EP1R;
  volatile uint16_t RESERVED1;
  volatile uint16_t EP2R;
  volatile uint16_t RESERVED2;
  volatile uint16_t EP3R;
  volatile uint16_t RESERVED3;
  volatile uint16_t EP4R;
  volatile uint16_t RESERVED4;
  volatile uint16_t EP5R;
  volatile uint16_t RESERVED5;
  volatile uint16_t EP6R;
  volatile uint16_t RESERVED6;
  volatile uint16_t EP7R;
  volatile uint16_t RESERVED7[17];
  volatile uint16_t CNTR;
  volatile uint16_t RESERVED8;
  volatile uint16_t ISTR;
  volatile uint16_t RESERVED9;
  volatile uint16_t FNR;
  volatile uint16_t RESERVEDA;
  volatile uint16_t DADDR;
  volatile uint16_t RESERVEDB;
  volatile uint16_t BTABLE;
  volatile uint16_t RESERVEDC;
  volatile uint16_t LPMCSR;
  volatile uint16_t RESERVEDD;
  volatile uint16_t BCDR;
  volatile uint16_t RESERVEDE;
} USB_TypeDef;





typedef struct
{
  volatile uint32_t CSR;
  volatile uint32_t CCR;
} VREFBUF_TypeDef;





typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFR;
  volatile uint32_t SR;
} WWDG_TypeDef;





typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t SR;
  volatile uint32_t DR;
} RNG_TypeDef;





typedef struct
{
  volatile uint32_t CSR;
  volatile uint32_t WDATA;
  volatile uint32_t RDATA;
} CORDIC_TypeDef;





typedef struct
{
  volatile uint32_t CFG1;
  volatile uint32_t CFG2;
  volatile uint32_t RESERVED0;
  volatile uint32_t CR;
  volatile uint32_t IMR;
  volatile uint32_t SR;
  volatile uint32_t ICR;
  volatile uint32_t TX_ORDSET;
  volatile uint32_t TX_PAYSZ;
  volatile uint32_t TXDR;
  volatile uint32_t RX_ORDSET;
  volatile uint32_t RX_PAYSZ;
  volatile uint32_t RXDR;
  volatile uint32_t RX_ORDEXT1;
  volatile uint32_t RX_ORDEXT2;
} UCPD_TypeDef;
# 109 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/CMSIS/Device/Include\\stm32g4xx.h" 2
# 138 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/CMSIS/Device/Include\\stm32g4xx.h"
typedef enum
{
  RESET = 0,
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum
{
  DISABLE = 0,
  ENABLE = !DISABLE
} FunctionalState;


typedef enum
{
  SUCCESS = 0,
  ERROR = !SUCCESS
} ErrorStatus;
# 21 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6\\utils.h" 2
# 1 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/STM32G4XX_LL_Drivers/Inc\\stm32g4xx_ll_cordic.h" 1
# 302 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/STM32G4XX_LL_Drivers/Inc\\stm32g4xx_ll_cordic.h"
static inline void LL_CORDIC_Config(CORDIC_TypeDef *CORDICx, uint32_t Function, uint32_t Precision, uint32_t Scale,
                                      uint32_t NbWrite, uint32_t NbRead, uint32_t InSize, uint32_t OutSize)
{
  (((CORDICx->CSR)) = ((((((CORDICx->CSR))) & (~((0xFUL << (0U)) | (0xFUL << (4U)) | (0x7UL << (8U)) | (0x1UL << (20U)) | (0x1UL << (19U)) | (0x1UL << (22U)) | (0x1UL << (21U))))) | (Function | Precision | Scale | NbWrite | NbRead | InSize | OutSize))));




}
# 329 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/STM32G4XX_LL_Drivers/Inc\\stm32g4xx_ll_cordic.h"
static inline void LL_CORDIC_SetFunction(CORDIC_TypeDef *CORDICx, uint32_t Function)
{
  (((CORDICx->CSR)) = ((((((CORDICx->CSR))) & (~((0xFUL << (0U))))) | (Function))));
}
# 350 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/STM32G4XX_LL_Drivers/Inc\\stm32g4xx_ll_cordic.h"
static inline uint32_t LL_CORDIC_GetFunction(CORDIC_TypeDef *CORDICx)
{
  return (uint32_t)(((CORDICx->CSR) & ((0xFUL << (0U)))));
}
# 377 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/STM32G4XX_LL_Drivers/Inc\\stm32g4xx_ll_cordic.h"
static inline void LL_CORDIC_SetPrecision(CORDIC_TypeDef *CORDICx, uint32_t Precision)
{
  (((CORDICx->CSR)) = ((((((CORDICx->CSR))) & (~((0xFUL << (4U))))) | (Precision))));
}
# 403 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/STM32G4XX_LL_Drivers/Inc\\stm32g4xx_ll_cordic.h"
static inline uint32_t LL_CORDIC_GetPrecision(CORDIC_TypeDef *CORDICx)
{
  return (uint32_t)(((CORDICx->CSR) & ((0xFUL << (4U)))));
}
# 423 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/STM32G4XX_LL_Drivers/Inc\\stm32g4xx_ll_cordic.h"
static inline void LL_CORDIC_SetScale(CORDIC_TypeDef *CORDICx, uint32_t Scale)
{
  (((CORDICx->CSR)) = ((((((CORDICx->CSR))) & (~((0x7UL << (8U))))) | (Scale))));
}
# 442 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/STM32G4XX_LL_Drivers/Inc\\stm32g4xx_ll_cordic.h"
static inline uint32_t LL_CORDIC_GetScale(CORDIC_TypeDef *CORDICx)
{
  return (uint32_t)(((CORDICx->CSR) & ((0x7UL << (8U)))));
}
# 456 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/STM32G4XX_LL_Drivers/Inc\\stm32g4xx_ll_cordic.h"
static inline void LL_CORDIC_SetNbWrite(CORDIC_TypeDef *CORDICx, uint32_t NbWrite)
{
  (((CORDICx->CSR)) = ((((((CORDICx->CSR))) & (~((0x1UL << (20U))))) | (NbWrite))));
}
# 469 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/STM32G4XX_LL_Drivers/Inc\\stm32g4xx_ll_cordic.h"
static inline uint32_t LL_CORDIC_GetNbWrite(CORDIC_TypeDef *CORDICx)
{
  return (uint32_t)(((CORDICx->CSR) & ((0x1UL << (20U)))));
}
# 483 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/STM32G4XX_LL_Drivers/Inc\\stm32g4xx_ll_cordic.h"
static inline void LL_CORDIC_SetNbRead(CORDIC_TypeDef *CORDICx, uint32_t NbRead)
{
  (((CORDICx->CSR)) = ((((((CORDICx->CSR))) & (~((0x1UL << (19U))))) | (NbRead))));
}
# 496 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/STM32G4XX_LL_Drivers/Inc\\stm32g4xx_ll_cordic.h"
static inline uint32_t LL_CORDIC_GetNbRead(CORDIC_TypeDef *CORDICx)
{
  return (uint32_t)(((CORDICx->CSR) & ((0x1UL << (19U)))));
}
# 510 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/STM32G4XX_LL_Drivers/Inc\\stm32g4xx_ll_cordic.h"
static inline void LL_CORDIC_SetInSize(CORDIC_TypeDef *CORDICx, uint32_t InSize)
{
  (((CORDICx->CSR)) = ((((((CORDICx->CSR))) & (~((0x1UL << (22U))))) | (InSize))));
}
# 523 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/STM32G4XX_LL_Drivers/Inc\\stm32g4xx_ll_cordic.h"
static inline uint32_t LL_CORDIC_GetInSize(CORDIC_TypeDef *CORDICx)
{
  return (uint32_t)(((CORDICx->CSR) & ((0x1UL << (22U)))));
}
# 537 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/STM32G4XX_LL_Drivers/Inc\\stm32g4xx_ll_cordic.h"
static inline void LL_CORDIC_SetOutSize(CORDIC_TypeDef *CORDICx, uint32_t OutSize)
{
  (((CORDICx->CSR)) = ((((((CORDICx->CSR))) & (~((0x1UL << (21U))))) | (OutSize))));
}
# 550 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/STM32G4XX_LL_Drivers/Inc\\stm32g4xx_ll_cordic.h"
static inline uint32_t LL_CORDIC_GetOutSize(CORDIC_TypeDef *CORDICx)
{
  return (uint32_t)(((CORDICx->CSR) & ((0x1UL << (21U)))));
}
# 569 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/STM32G4XX_LL_Drivers/Inc\\stm32g4xx_ll_cordic.h"
static inline void LL_CORDIC_EnableIT(CORDIC_TypeDef *CORDICx)
{
  ((CORDICx->CSR) |= ((0x1UL << (16U))));
}







static inline void LL_CORDIC_DisableIT(CORDIC_TypeDef *CORDICx)
{
  ((CORDICx->CSR) &= ~((0x1UL << (16U))));
}







static inline uint32_t LL_CORDIC_IsEnabledIT(CORDIC_TypeDef *CORDICx)
{
  return ((((CORDICx->CSR) & ((0x1UL << (16U)))) == ((0x1UL << (16U)))) ? 1U : 0U);
}
# 610 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/STM32G4XX_LL_Drivers/Inc\\stm32g4xx_ll_cordic.h"
static inline void LL_CORDIC_EnableDMAReq_RD(CORDIC_TypeDef *CORDICx)
{
  ((CORDICx->CSR) |= ((0x1UL << (17U))));
}







static inline void LL_CORDIC_DisableDMAReq_RD(CORDIC_TypeDef *CORDICx)
{
  ((CORDICx->CSR) &= ~((0x1UL << (17U))));
}







static inline uint32_t LL_CORDIC_IsEnabledDMAReq_RD(CORDIC_TypeDef *CORDICx)
{
  return ((((CORDICx->CSR) & ((0x1UL << (17U)))) == ((0x1UL << (17U)))) ? 1U : 0U);
}







static inline void LL_CORDIC_EnableDMAReq_WR(CORDIC_TypeDef *CORDICx)
{
  ((CORDICx->CSR) |= ((0x1UL << (18U))));
}







static inline void LL_CORDIC_DisableDMAReq_WR(CORDIC_TypeDef *CORDICx)
{
  ((CORDICx->CSR) &= ~((0x1UL << (18U))));
}







static inline uint32_t LL_CORDIC_IsEnabledDMAReq_WR(CORDIC_TypeDef *CORDICx)
{
  return ((((CORDICx->CSR) & ((0x1UL << (18U)))) == ((0x1UL << (18U)))) ? 1U : 0U);
}
# 680 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/STM32G4XX_LL_Drivers/Inc\\stm32g4xx_ll_cordic.h"
static inline uint32_t LL_CORDIC_DMA_GetRegAddr(CORDIC_TypeDef *CORDICx, uint32_t Direction)
{
  uint32_t data_reg_addr;

  if (Direction == (0x00000001U))
  {

    data_reg_addr = (uint32_t) &(CORDICx->RDATA);
  }
  else
  {

    data_reg_addr = (uint32_t) &(CORDICx->WDATA);
  }

  return data_reg_addr;
}
# 712 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/STM32G4XX_LL_Drivers/Inc\\stm32g4xx_ll_cordic.h"
static inline uint32_t LL_CORDIC_IsActiveFlag_RRDY(CORDIC_TypeDef *CORDICx)
{
  return ((((CORDICx->CSR) & ((0x1UL << (31U)))) == ((0x1UL << (31U)))) ? 1U : 0U);
}
# 732 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/STM32G4XX_LL_Drivers/Inc\\stm32g4xx_ll_cordic.h"
static inline void LL_CORDIC_WriteData(CORDIC_TypeDef *CORDICx, uint32_t InData)
{
  ((CORDICx->WDATA) = (InData));
}







static inline uint32_t LL_CORDIC_ReadData(CORDIC_TypeDef *CORDICx)
{
  return (uint32_t)(((CORDICx->RDATA)));
}
# 758 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/STM32G4xx/STM32G4XX_LL_Drivers/Inc\\stm32g4xx_ll_cordic.h"
ErrorStatus LL_CORDIC_DeInit(CORDIC_TypeDef *CORDICx);
# 22 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6\\utils.h" 2
# 35 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6\\utils.h"
static inline void fsat(float *num, float min, float max)
{
  if (*num > max) {
    *num = max;
  } else if (*num < min) {
    *num = min;
  }
}



static inline void norm_angle(float *angle)
{
  while (*angle < -3.14159265358979323846) { *angle += 2.0 * 3.14159265358979323846; }
  while (*angle >= 3.14159265358979323846) { *angle -= 2.0 * 3.14159265358979323846; }
}
# 59 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6\\utils.h"
static inline void cordic_sincos(float angle, float *sin, float *cos)
{
  int cordic_input = (int)(angle * 6.8356527557643158978229477811035e8f);
  LL_CORDIC_Config(((CORDIC_TypeDef *) (((0x40000000UL) + 0x00020000UL) + 0x0C00UL)),
                  ((uint32_t)((0x1UL << (0U)))),
                  ((uint32_t)((0x4UL << (4U)) | (0x2UL << (4U)))),
                  (0x00000000U),
                  (0x00000000U),
                  (0x1UL << (19U)),
                  (0x00000000U),
                  (0x00000000U));
  LL_CORDIC_WriteData(((CORDIC_TypeDef *) (((0x40000000UL) + 0x00020000UL) + 0x0C00UL)), cordic_input);
  *sin = (float)((int)LL_CORDIC_ReadData(((CORDIC_TypeDef *) (((0x40000000UL) + 0x00020000UL) + 0x0C00UL)))) * 4.656612873077392578125e-10f;
  *cos = (float)((int)LL_CORDIC_ReadData(((CORDIC_TypeDef *) (((0x40000000UL) + 0x00020000UL) + 0x0C00UL)))) * 4.656612873077392578125e-10f;
}






static inline void cordic_atan2(float x, float y, float *theta)
{

  int x_arg = (int)(x * 6.8356527557643158978229477811035e8f);
  int y_arg = (int)(y * 6.8356527557643158978229477811035e8f);


  LL_CORDIC_Config(((CORDIC_TypeDef *) (((0x40000000UL) + 0x00020000UL) + 0x0C00UL)),
                  ((uint32_t)((0x2UL << (0U)))),
                  ((uint32_t)((0x4UL << (4U)) | (0x2UL << (4U)))),
                  (0x00000000U),
                  (0x1UL << (20U)),
                  (0x00000000U),
                  (0x00000000U),
                  (0x00000000U));
  LL_CORDIC_WriteData(((CORDIC_TypeDef *) (((0x40000000UL) + 0x00020000UL) + 0x0C00UL)), x_arg);
  LL_CORDIC_WriteData(((CORDIC_TypeDef *) (((0x40000000UL) + 0x00020000UL) + 0x0C00UL)), y_arg);



  *theta = (float)((int)LL_CORDIC_ReadData(((CORDIC_TypeDef *) (((0x40000000UL) + 0x00020000UL) + 0x0C00UL)))) * 1.4629180792671596810513378043098e-9f;
}


void vesc_fast_sincos(float angle, float *sin, float *cos);




static inline void float_to_q31(float *pSrc, int *pDst)
{
  *pDst = (uint32_t)(*pSrc * 2147483648.0f);
}
# 16 "C:/Users/goldf/OneDrive/pc-sync/SEGGER Embedded Studio for ARM Projects/G431CBU6/foc/clarke.h" 2


static inline void clarke_full_run(float *abc, float *ab)
{
  ab[0] = 1.0f / 3.0f * (2.0f * abc[0]) - 1.0f / 3.0f * (abc[1] + abc[2]);
  ab[1] = 0.577350269189626f * (abc[1] - abc[2]);
}






static inline void iclarke_run(float *ab, float *abc)
{
  abc[0] = ab[0];
  abc[1] = -(0.5f * ab[0]) + (0.866025403784439f * ab[1]);
  abc[2] = (0.5f * ab[0]) - (0.866025403784439f * ab[1]);
}
# 44 "C:\\Users\\goldf\\OneDrive\\pc-sync\\SEGGER Embedded Studio for ARM Projects\\G431CBU6\\foc\\clarke.c" 2

