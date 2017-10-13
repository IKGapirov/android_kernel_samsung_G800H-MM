/*
 *
 * Copyright 2011-2012 Maxim Integrated Products
 *
 *  This program is free software; you can redistribute  it and/or modify it
 *  under  the terms of  the GNU General  Public License as published by the
 *  Free Software Foundation;  either version 2 of the  License, or (at your
 *  option) any later version.
 *
 */

#ifndef __SOUND_MAXIM_DSM_H__
#define __SOUND_MAXIM_DSM_H__

#define DSM_RX_PORT_ID	0x4000

#define AFE_PARAM_ID_ENABLE_DSM_RX    0x10001062
#define AFE_PARAM_ID_ENABLE_DSM_TX    0x10001063

#define DSM_ID_FILTER_GET_AFE_PARAMS 0x00000000
#define DSM_ID_FILTER_SET_AFE_CNTRLS 0x00000001

#define FLAG_WRITE_ALL 0xabefcdab
#define FLAG_WRITE_CAL_FROM_FILE 0xffff0000
#define FLAG_WRITE_ONOFF_ONLY	0xcdababef
#define FLAG_WRITE_RDC_CAL_ONLY 0xca00ca00
#define FLAG_WRITE_FEATURE_ONLY 0xfea0fea0

#define RESERVED_ADDR_COUNT		0xFF
#define START_ADDR_FOR_LSI		0x2A004C
#define END_ADDR_FOR_LSI		(0x2A027A + RESERVED_ADDR_COUNT)

enum maxdsm_version {
	VERSION_3_0 = 30,
	VERSION_3_5_A = 35,
	VERSION_3_5_B,
	VERSION_4_0_A = 40,
	VERSION_4_0_B,
};

enum maxdsm_platform_type {
	PLATFORM_TYPE_A = 0,
	PLATFORM_TYPE_B,
};

enum maxdsm_ioctl_cmds {
	MAXDSM_IOCTL_GET_VERSION = 1000,
	MAXDSM_IOCTL_SET_VERSION,
	MAXDSM_IOCTL_GET_PARAM,
	MAXDSM_IOCTL_SET_PARAM,
	MAXDSM_IOCTL_GET_ALL_PARAMS,
	MAXDSM_IOCTL_SET_ALL_PARAMS,
	MAXDSM_IOCTL_GET_CAL_DATA,
	MAXDSM_IOCTL_SET_CAL_DATA,
	MAXDSM_IOCTL_GET_PLATFORM_TYPE,
	MAXDSM_IOCTL_SET_PLATFORM_TYPE,
};

enum maxdsm_ignore_param {
	MAXDSM_IGNORE_MASK_VOICE_COIL = 1U << 0,
	MAXDSM_IGNORE_MASK_AMBIENT_TEMP = 1U << 1,
	MAXDSM_IGNORE_MASK_ALL	= 1U << 16,
};

enum maxdsm_offset {
	PARAM_OFFSET_PLATFORM,
	PARAM_OFFSET_PORT_ID,
	PARAM_OFFSET_RX_MOD_ID,
	PARAM_OFFSET_TX_MOD_ID,
	PARAM_OFFSET_FILTER_SET,
	PARAM_OFFSET_VERSION,
	PARAM_OFFSET_MAX,
};

enum maxdsm_3_0_params {
	PARAM_RDC,
	PARAM_RDC_SZ,
	PARAM_VOICE_COIL_TEMP,
	PARAM_VOICE_COIL_TEMP_SZ,
	PARAM_Q,
	PARAM_Q_SZ,
	PARAM_FRES,
	PARAM_FRES_SZ,
	PARAM_EXCURSION,
	PARAM_EXCURSION_SZ,
	PARAM_VOICE_COIL,
	PARAM_VOICE_COIL_SZ,
	PARAM_RELEASE_TIME,
	PARAM_RELEASE_TIME_SZ,
	PARAM_THERMAL_LIMIT,
	PARAM_THERMAL_LIMIT_SZ,
	PARAM_EXCUR_LIMIT,
	PARAM_EXCUR_LIMIT_SZ,
	PARAM_ONOFF,
	PARAM_ONOFF_SZ,
	PARAM_STATIC_GAIN,
	PARAM_STATIC_GAIN_SZ,
	PARAM_LFX_GAIN,
	PARAM_LFX_GAIN_SZ,
	PARAM_PILOT_GAIN,
	PARAM_PILOT_GAIN_SZ,
	PARAM_WRITE_FLAG,
	PARAM_WRITE_FLAG_SZ,
	PARAM_FEATURE_SET,
	PARAM_FEATURE_SET_SZ,
	PARAM_SMOOTH_VOLT,
	PARAM_SMOOTH_VOLT_SZ,
	PARAM_HPF_CUTOFF,
	PARAM_HPF_CUTOFF_SZ,
	PARAM_LEAD_R,
	PARAM_LEAD_R_SZ,
	PARAM_RMS_SMOO_FAC,
	PARAM_RMS_SMOO_FAC_SZ,
	PARAM_CLIP_LIMIT,
	PARAM_CLIP_LIMIT_SZ,
	PARAM_THERMAL_COEF,
	PARAM_THERMAL_COEF_SZ,
	PARAM_QSPK,
	PARAM_QSPK_SZ,
	PARAM_EXCUR_LOG_THRESH,
	PARAM_EXCUR_LOG_THRESH_SZ,
	PARAM_TEMP_LOG_THRESH,
	PARAM_TEMP_LOG_THRESH_SZ,
	PARAM_RES_FREQ,
	PARAM_RES_FREQ_SZ,
	PARAM_RES_FREQ_GUARD_BAND,
	PARAM_RES_FREQ_GUARD_BAND_SZ,
	PARAM_DSM_3_0_MAX,
};

enum maxdsm_3_5_params {
	PARAM_AMBIENT_TEMP = PARAM_DSM_3_0_MAX,
	PARAM_AMBIENT_TEMP_SZ,
	PARAM_STL_ATTACK_TIME,
	PARAM_STL_ATTACK_TIME_SZ,
	PARAM_STL_RELEASE_TIME,
	PARAM_STL_RELEASE_TIME_SZ,
	PARAM_ADMITTANCE_A1,
	PARAM_ADMITTANCE_A1_SZ,
	PARAM_ADMITTANCE_A2,
	PARAM_ADMITTANCE_A2_SZ,
	PARAM_ADMITTANCE_B0,
	PARAM_ADMITTANCE_B0_SZ,
	PARAM_ADMITTANCE_B1,
	PARAM_ADMITTANCE_B1_SZ,
	PARAM_ADMITTANCE_B2,
	PARAM_ADMITTANCE_B2_SZ,
	PARAM_TCH1,
	PARAM_TCH1_SZ,
	PARAM_RTH1,
	PARAM_RTH1_SZ,
	PARAM_TCH2,
	PARAM_TCH2_SZ,
	PARAM_RTH2,
	PARAM_RTH2_SZ,
	PARAM_STL_ATTENUATION_GAIN,
	PARAM_STL_ATTENUATION_GAIN_SZ,
	PARAM_SPT_RAMP_DOWN_FRAMES,
	PARAM_SPT_RAMP_DOWN_FRAMES_SZ,
	PARAM_SPT_THRESHOLD,
	PARAM_SPT_THRESHOLD_SZ,
	PARAM_T_HORIZON,
	PARAM_T_HORIZON_SZ,
	PARAM_LFX_ADMITTANCE_A1,
	PARAM_LFX_ADMITTANCE_A1_SZ,
	PARAM_LFX_ADMITTANCE_A2,
	PARAM_LFX_ADMITTANCE_A2_SZ,
	PARAM_LFX_ADMITTANCE_B0,
	PARAM_LFX_ADMITTANCE_B0_SZ,
	PARAM_LFX_ADMITTANCE_B1,
	PARAM_LFX_ADMITTANCE_B1_SZ,
	PARAM_LFX_ADMITTANCE_B2,
	PARAM_LFX_ADMITTANCE_B2_SZ,
	PARAM_DSM_3_5_MAX,
};

enum maxdsm_4_0_params {
	PARAM_X_MAX = PARAM_DSM_3_5_MAX,
	PARAM_X_MAX_SZ,
	PARAM_SPK_FS,
	PARAM_SPK_FS_SZ,
	PARAM_Q_GUARD_BAND,
	PARAM_Q_GUARD_BAND_SZ,
	PARAM_STIMPEDMODEL_COEFFS_A1,
	PARAM_STIMPEDMODEL_COEFFS_A1_SZ,
	PARAM_STIMPEDMODEL_COEFFS_A2,
	PARAM_STIMPEDMODEL_COEFFS_A2_SZ,
	PARAM_STIMPEDMODEL_COEFFS_B0,
	PARAM_STIMPEDMODEL_COEFFS_B0_SZ,
	PARAM_STIMPEDMODEL_COEFFS_B1,
	PARAM_STIMPEDMODEL_COEFFS_B1_SZ,
	PARAM_STIMPEDMODEL_COEFFS_B2,
	PARAM_STIMPEDMODEL_COEFFS_B2_SZ,
	PARAM_STIMPEDMODEL_FLAG,
	PARAM_STIMPEDMODEL_FLAG_SZ,
	PARAM_Q_NOTCH,
	PARAM_Q_NOTCH_SZ,
	PARAM_DSM_4_0_MAX,
};

enum maxdsm_3_0_params_a {
	PARAM_A_VOICE_COIL_TEMP,
	PARAM_A_VOICE_COIL_TEMP_SZ,
	PARAM_A_EXCURSION,
	PARAM_A_EXCURSION_SZ,
	PARAM_A_RDC,
	PARAM_A_RDC_SZ,
	PARAM_A_Q_LO,
	PARAM_A_Q_LO_SZ,
	PARAM_A_Q_HI,
	PARAM_A_Q_HI_SZ,
	PARAM_A_FRES_LO,
	PARAM_A_FRES_LO_SZ,
	PARAM_A_FRES_HI,
	PARAM_A_FRES_HI_SZ,
	PARAM_A_EXCUR_LIMIT,
	PARAM_A_EXCUR_LIMIT_SZ,
	PARAM_A_VOICE_COIL,
	PARAM_A_VOICE_COIL_SZ,
	PARAM_A_THERMAL_LIMIT,
	PARAM_A_THERMAL_LIMIT_SZ,
	PARAM_A_RELEASE_TIME,
	PARAM_A_RELEASE_TIME_SZ,
	PARAM_A_ONOFF,
	PARAM_A_ONOFF_SZ,
	PARAM_A_STATIC_GAIN,
	PARAM_A_STATIC_GAIN_SZ,
	PARAM_A_LFX_GAIN,
	PARAM_A_LFX_GAIN_SZ,
	PARAM_A_PILOT_GAIN,
	PARAM_A_PILOT_GAIN_SZ,
	PARAM_A_FEATURE_SET,
	PARAM_A_FEATURE_SET_SZ,
	PARAM_A_SMOOTH_VOLT,
	PARAM_A_SMOOTH_VOLT_SZ,
	PARAM_A_HPF_CUTOFF,
	PARAM_A_HPF_CUTOFF_SZ,
	PARAM_A_LEAD_R,
	PARAM_A_LEAD_R_SZ,
	PARAM_A_RMS_SMOO_FAC,
	PARAM_A_RMS_SMOO_FAC_SZ,
	PARAM_A_CLIP_LIMIT,
	PARAM_A_CLIP_LIMIT_SZ,
	PARAM_A_THERMAL_COEF,
	PARAM_A_THERMAL_COEF_SZ,
	PARAM_A_QSPK,
	PARAM_A_QSPK_SZ,
	PARAM_A_EXCUR_LOG_THRESH,
	PARAM_A_EXCUR_LOG_THRESH_SZ,
	PARAM_A_TEMP_LOG_THRESH,
	PARAM_A_TEMP_LOG_THRESH_SZ,
	PARAM_A_RES_FREQ,
	PARAM_A_RES_FREQ_SZ,
	PARAM_A_RES_FREQ_GUARD_BAND,
	PARAM_A_RES_FREQ_GUARD_BAND_SZ,
	PARAM_A_DSM_3_0_MAX,
};

enum maxdsm_3_5_params_a {
	PARAM_A_AMBIENT_TEMP = PARAM_A_DSM_3_0_MAX,
	PARAM_A_AMBIENT_TEMP_SZ,
	PARAM_A_ADMITTANCE_A1,
	PARAM_A_ADMITTANCE_A1_SZ,
	PARAM_A_ADMITTANCE_A2,
	PARAM_A_ADMITTANCE_A2_SZ,
	PARAM_A_ADMITTANCE_B0,
	PARAM_A_ADMITTANCE_B0_SZ,
	PARAM_A_ADMITTANCE_B1,
	PARAM_A_ADMITTANCE_B1_SZ,
	PARAM_A_ADMITTANCE_B2,
	PARAM_A_ADMITTANCE_B2_SZ,
	PARAM_A_RTH1_HI,
	PARAM_A_RTH1_HI_SZ,
	PARAM_A_RTH1_LO,
	PARAM_A_RTH1_LO_SZ,
	PARAM_A_RTH2_HI,
	PARAM_A_RTH2_HI_SZ,
	PARAM_A_RTH2_LO,
	PARAM_A_RTH2_LO_SZ,
	PARAM_A_STL_ATENGAIN_HI,
	PARAM_A_STL_ATENGAIN_HI_SZ,
	PARAM_A_STL_ATENGAIN_LO,
	PARAM_A_STL_ATENGAIN_LO_SZ,
	PARAM_A_SPT_RAMP_DOWN_FRAMES,
	PARAM_A_SPT_RAMP_DOWN_FRAMES_SZ,
	PARAM_A_SPT_THRESHOLD_HI,
	PARAM_A_SPT_THRESHOLD_HI_SZ,
	PARAM_A_SPT_THRESHOLD_LO,
	PARAM_A_SPT_THRESHOLD_LO_SZ,
	PARAM_A_T_HORIZON,
	PARAM_A_T_HORIZON_SZ,
	PARAM_A_LFX_ADMITTANCE_A1,
	PARAM_A_LFX_ADMITTANCE_A1_SZ,
	PARAM_A_LFX_ADMITTANCE_A2,
	PARAM_A_LFX_ADMITTANCE_A2_SZ,
	PARAM_A_LFX_ADMITTANCE_B0,
	PARAM_A_LFX_ADMITTANCE_B0_SZ,
	PARAM_A_LFX_ADMITTANCE_B1,
	PARAM_A_LFX_ADMITTANCE_B1_SZ,
	PARAM_A_LFX_ADMITTANCE_B2,
	PARAM_A_LFX_ADMITTANCE_B2_SZ,
	PARAM_A_ALGORITHM_X_MAX,
	PARAM_A_ALGORITHM_X_MAX_SZ,
	PARAM_A_DSM_3_5_MAX,
};

enum maxdsm_4_0_params_a {
	PARAM_A_STL_TCTH1_HI = PARAM_A_DSM_3_5_MAX,
	PARAM_A_STL_TCTH1_HI_SZ,
	PARAM_A_STL_TCTH1_LO,
	PARAM_A_STL_TCTH1_LO_SZ,
	PARAM_A_STL_TCTH2_HI,
	PARAM_A_STL_TCTH2_HI_SZ,
	PARAM_A_STL_TCTH2_LO,
	PARAM_A_STL_TCTH2_LO_SZ,
	PARAM_A_STL_ATTACK_HI,
	PARAM_A_STL_ATTACK_HI_SZ,
	PARAM_A_STL_ATTACK_LO,
	PARAM_A_STL_ATTACK_LO_SZ,
	PARAM_A_STL_RELEASE_HI,
	PARAM_A_STL_RELEASE_HI_SZ,
	PARAM_A_STL_RELEASE_LO,
	PARAM_A_STL_RELEASE_LO_SZ,
	PARAM_A_STL_SPK_FS,
	PARAM_A_STL_SPK_FS_SZ,
	PARAM_A_Q_GUARD_BAND_HI,
	PARAM_A_Q_GUARD_BAND_HI_SZ,
	PARAM_A_Q_GUARD_BAND_LO,
	PARAM_A_Q_GUARD_BAND_LO_SZ,
	PARAM_A_STIMPEDMODEL_COEFFS_A1_HI,
	PARAM_A_STIMPEDMODEL_COEFFS_A1_HI_SZ,
	PARAM_A_STIMPEDMODEL_COEFFS_A1_LO,
	PARAM_A_STIMPEDMODEL_COEFFS_A1_LO_SZ,
	PARAM_A_STIMPEDMODEL_COEFFS_A2_HI,
	PARAM_A_STIMPEDMODEL_COEFFS_A2_HI_SZ,
	PARAM_A_STIMPEDMODEL_COEFFS_A2_LO,
	PARAM_A_STIMPEDMODEL_COEFFS_A2_LO_SZ,
	PARAM_A_STIMPEDMODEL_COEFFS_B0_HI,
	PARAM_A_STIMPEDMODEL_COEFFS_B0_HI_SZ,
	PARAM_A_STIMPEDMODEL_COEFFS_B0_LO,
	PARAM_A_STIMPEDMODEL_COEFFS_B0_LO_SZ,
	PARAM_A_STIMPEDMODEL_COEFFS_B1_HI,
	PARAM_A_STIMPEDMODEL_COEFFS_B1_HI_SZ,
	PARAM_A_STIMPEDMODEL_COEFFS_B1_LO,
	PARAM_A_STIMPEDMODEL_COEFFS_B1_LO_SZ,
	PARAM_A_STIMPEDMODEL_COEFFS_B2_HI,
	PARAM_A_STIMPEDMODEL_COEFFS_B2_HI_SZ,
	PARAM_A_STIMPEDMODEL_COEFFS_B2_LO,
	PARAM_A_STIMPEDMODEL_COEFFS_B2_LO_SZ,
	PARAM_A_STIMPEDMODEL_FLAG,
	PARAM_A_STIMPEDMODEL_FLAG_SZ,
	PARAM_A_Q_NOTCH_HI,
	PARAM_A_Q_NOTCH_HI_SZ,
	PARAM_A_Q_NOTCH_LO,
	PARAM_A_Q_NOTCH_LO_SZ,
	PARAM_A_DSM_4_0_MAX,
};

enum {
	WRITE_PROTECT,
	LOG_AVAILABLE,
	VERSION_INFO,
	LAST_2_SEC_TEMP,
	LAST_2_SEC_EXCUR,
	RESERVED_1,
	SEQUENCE_OF_TEMP,
	SEQUENCE_OF_EXCUR,
	LAST_2_SEC_RDC,
	LAST_2_SEC_FREQ,
	RESERVED_2,
	RESERVED_3,
	AFTER_2_SEC_TEMP_TEMP,
	AFTER_2_SEC_EXCUR_TEMP,
	AFTER_2_SEC_TEMP_EXCUR,
	AFTER_2_SEC_EXCUR_EXCUR,
	AFTER_2_SEC_RDC_TEMP,
	AFTER_2_SEC_FREQ_TEMP,
	AFTER_2_SEC_RDC_EXCUR,
	AFTER_2_SEC_FREQ_EXCUR,
	MAX_LOG_BUFFER_POS,
};

struct param_info {
	int id;
	uint32_t addr;
	int size;
	int type;
	int val;
};

struct param_set_data {
	int name;
	uint32_t addr;
	uint32_t value;
	uint32_t wflag;
};

struct maxim_dsm {
	struct regmap *regmap;
	uint32_t *param;
	uint32_t param_size;
	uint32_t platform_type;
	uint32_t port_id;
	uint32_t rx_mod_id;
	uint32_t tx_mod_id;
	uint32_t filter_set;
	uint32_t version;
	uint32_t *binfo;
	uint32_t registered;
	uint32_t update_cal;
	uint32_t ignore_mask;
	uint32_t spk_state;
};

#ifdef CONFIG_SND_SOC_MAXIM_DSM
#define USE_DSM_UPDATE_CAL
#define USE_DSM_LOG
#define USE_DSM_DEBUG
#endif /* CONFIG_SND_SOC_MAXIM_DSM */

int maxdsm_init(void);
int maxdsm_deinit(void);

uint32_t maxdsm_get_platform_type(void);
int maxdsm_set_feature_en(int on);
int maxdsm_set_rdc_temp(uint32_t rdc, uint32_t temp);
int maxdsm_set_dsm_onoff_status(int on);
uint32_t maxdsm_get_dcresistance(void);

int maxdsm_update_info(uint32_t *pinfo);
int maxdsm_get_port_id(void);
int maxdsm_get_rx_mod_id(void);
int maxdsm_get_tx_mod_id(void);
void maxdsm_set_regmap(struct regmap *regmap);

int maxdsm_update_feature_en_adc(int apply);

int maxdsm_get_spk_state(void);
void maxdsm_set_spk_state(int state);
int maxdsm_set_pilot_signal_state(int on);

#ifdef USE_DSM_LOG
#define LOG_BUFFER_ARRAY_SIZE 10

/* BUFSIZE must be 4 bytes allignment*/
#define BEFORE_BUFSIZE (4+(LOG_BUFFER_ARRAY_SIZE*2))
#define AFTER_BUFSIZE (LOG_BUFFER_ARRAY_SIZE*4)

int maxdsm_get_dump_status(void);
void maxdsm_update_param(void);
void maxdsm_log_update(const void *byte_log_array,
		const void *int_log_array,
		const void *after_prob_byte_log_array,
		const void *after_prob_int_log_array);
ssize_t maxdsm_log_prepare(char *buf);
void maxdsm_cal_update(const void *byte_log_array,
		const void *int_log_array,
		const void *after_prob_byte_log_array,
		const void *after_prob_int_log_array);
#endif /* USE_DSM_LOG */

#ifdef USE_DSM_UPDATE_CAL
int maxdsm_cal_avail(void);
int maxdsm_update_caldata(int on);
ssize_t maxdsm_cal_prepare(char *buf);
#endif

#endif /* __SOUND_MAXIM_DSM_H__ */
