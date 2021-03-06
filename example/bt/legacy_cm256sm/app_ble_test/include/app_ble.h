/*****************************************************************************
**
**  Name:           app_ble.h
**
**  Description:    Bluetooth BLE include file
**
**  Copyright (c) 2015, Broadcom Corp., All Rights Reserved.
**  Broadcom Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef APP_BLE_H
#define APP_BLE_H

#include "bsa_api.h"

typedef struct
{
    tBT_UUID        service_UUID;
    BOOLEAN         enabled;
    tBSA_BLE_IF     client_if;
    UINT16          conn_id;
    BD_ADDR         server_addr;
    BOOLEAN         write_pending;
    BOOLEAN         read_pending;
    BOOLEAN         congested;
} tAPP_BLE_CLIENT;

typedef struct
{
    tBT_UUID            char_uuid;
    tBSA_BLE_PERM       perm;
    tBSA_BLE_CHAR_PROP  property;
    UINT32 char_handle; /*characteristic characteristic handle number*/
    UINT32 char_id; /*characteristic characteristic number*/
} tAPP_BLE_CHAR;

typedef struct
{
    tBT_UUID       attr_UUID;
    UINT16         service_id;
    UINT16         attr_id;
    UINT8          attr_type;
    UINT8          prop;
    BOOLEAN        is_pri;
    BOOLEAN        wait_flag;
    UINT8              current_char;
    tAPP_BLE_CHAR characteristic[BSA_BLE_CHAR_MAX];
} tAPP_BLE_SERVICE;

typedef struct 
{
    BOOLEAN       enabled;
    tBSA_BLE_IF server_if;
    UINT16            conn_id;
    UINT8              current_service;
    tAPP_BLE_SERVICE  attr[BSA_BLE_ATTRIBUTE_MAX];
} tAPP_BLE_SERVER;

typedef struct
{
    tAPP_BLE_CLIENT ble_client[BSA_BLE_CLIENT_MAX];
    UINT8 current_server;
    tAPP_BLE_SERVER ble_server[BSA_BLE_SERVER_MAX];
} tAPP_BLE_CB;

/*
 * Global Variables
 */
extern tAPP_BLE_CB app_ble_cb;


/*******************************************************************************
 **
 ** Function         app_av_display_vendor_commands
 **
 ** Description      This function display the name of vendor dependent command
 **
 ** Returns          void
 **
 *******************************************************************************/
char *app_ble_display_service_name(UINT16 uuid);

/*******************************************************************************
 **
 ** Function        app_ble_init
 **
 ** Description     This is the main init function
 **
 ** Parameters      None
 **
 ** Returns         status: 0 if success / -1 otherwise
 **
 *******************************************************************************/
int app_ble_init(void);

/*******************************************************************************
 **
 ** Function        app_ble_exit
 **
 ** Description     This is the ble exit function
 **
 ** Parameters      None
 **
 ** Returns         status: 0 if success / -1 otherwise
 **
 *******************************************************************************/
int app_ble_exit(void);

/*******************************************************************************
 **
 ** Function        app_ble_start
 **
 ** Description     DTV Start function
 **
 ** Parameters      None
 **
 ** Returns         status: 0 if success / -1 otherwise
 **
 *******************************************************************************/
int app_ble_start(void);

/*******************************************************************************
 **
 ** Function        app_ble_wake_configure
 **
 ** Description     Configure for Wake on BLE
 **
 ** Parameters      None
 **
 ** Returns         status: 0 if success / -1 otherwise
 **
 *******************************************************************************/
int app_ble_wake_configure(void);

/*******************************************************************************
 **
 ** Function        app_ble_apcf_enable
 **
 ** Description     Enable APCF
 **
 ** Parameters      None
 **
 ** Returns         status: 0 if success / -1 otherwise
 **
 *******************************************************************************/
int app_ble_apcf_enable(void);

/*******************************************************************************
 **
 ** Function        app_ble_apcf_disable
 **
 ** Description     Disable APCF
 **
 ** Parameters      None
 **
 ** Returns         status: 0 if success / -1 otherwise
 **
 *******************************************************************************/
int app_ble_apcf_disable(void);

/*******************************************************************************
 **
 ** Function        app_ble_apcf_cfg
 **
 ** Description     Config APCF
 **
 ** Parameters      None
 **
 ** Returns         status: 0 if success / -1 otherwise
 **
 *******************************************************************************/
int app_ble_apcf_cfg(void);

#endif
