// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2019-2022, Alex Taradov <alex@taradov.com>. All rights reserved.

#ifndef _USB_DESCRIPTORS_H_
#define _USB_DESCRIPTORS_H_

/*- Includes ----------------------------------------------------------------*/
#include "usb_std.h"
#include "usb_cdc.h"
#include "usb_hid.h"
#include "hal_config.h"

/*- Definitions -------------------------------------------------------------*/
#define USB_BCD_VERSION      0x0200

enum
{
  USB_STR_ZERO,
  USB_STR_MANUFACTURER,
  USB_STR_PRODUCT,
  USB_STR_SERIAL_NUMBER,
  USB_STR_COUNT,
};

enum
{
  USB_CDC_EP_COMM  = 1,
  USB_CDC_EP_SEND  = 2,
  USB_CDC_EP_RECV  = 3,
};

enum
{
  USB_INTF_CDC_COMM,
  USB_INTF_CDC_DATA,
  USB_INTF_COUNT,
};

/*- Types -------------------------------------------------------------------*/
typedef struct USB_PACK
{
  usb_configuration_descriptor_t                   configuration;
  usb_interface_association_descriptor_t           iad;
  usb_interface_descriptor_t                       interface_comm;
  usb_cdc_header_functional_descriptor_t           cdc_header;
  usb_cdc_abstract_control_managment_descriptor_t  cdc_acm;
  usb_cdc_call_managment_functional_descriptor_t   cdc_call_mgmt;
  usb_cdc_union_functional_descriptor_t            cdc_union;
  usb_endpoint_descriptor_t                        ep_comm;
  usb_interface_descriptor_t                       interface_data;
  usb_endpoint_descriptor_t                        ep_in;
  usb_endpoint_descriptor_t                        ep_out;
} usb_configuration_hierarchy_t;

//-----------------------------------------------------------------------------
extern const usb_device_descriptor_t usb_device_descriptor;
extern const usb_configuration_hierarchy_t usb_configuration_hierarchy;
extern const usb_string_descriptor_zero_t usb_string_descriptor_zero;
extern const char *usb_strings[];
extern const usb_class_handler_t usb_class_handlers[1];
extern char usb_serial_number[8+1];

#endif // _USB_DESCRIPTORS_H_
