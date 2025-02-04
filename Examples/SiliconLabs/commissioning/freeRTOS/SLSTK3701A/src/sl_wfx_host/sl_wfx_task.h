/**************************************************************************//**
 * Copyright 2019, Silicon Laboratories Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#ifndef SL_WFX_TASK_H
#define SL_WFX_TASK_H

#include <stdbool.h>

#include "cmsis_os.h"

#include  "sl_wfx_constants.h"
#include  "sl_wfx_cmd_api.h"

typedef struct {
  sl_wfx_send_frame_req_t *frame;
  uint32_t data_length;
  sl_wfx_interface_t interface;
  uint8_t priority;
} wfx_frame_q_item;

extern wfx_frame_q_item wfxtask_tx_frame;
extern sl_wfx_context_t wifi;

#ifdef __cplusplus
extern "C" {
#endif
/**************************************************************************//**
 * Start wfx bus communication task.
 *****************************************************************************/
void wfx_bus_start(void);

/**************************************************************************//**
 * Returns status of wfx receive frames.
 *****************************************************************************/
bool wfxtask_is_receive_processing(void);

#ifdef __cplusplus
}
#endif

#endif
