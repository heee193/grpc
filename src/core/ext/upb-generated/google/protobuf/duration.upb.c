/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     google/protobuf/duration.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/collections/array_internal.h"
#include "upb/message/internal.h"
#include "upb/mini_table/enum_internal.h"
#include "google/protobuf/duration.upb.h"

// Must be last.
#include "upb/port/def.inc"

static const upb_MiniTableField google_protobuf_Duration__fields[2] = {
  {1, 8, 0, kUpb_NoSub, 3, kUpb_FieldMode_Scalar | (kUpb_FieldRep_8Byte << kUpb_FieldRep_Shift)},
  {2, 0, 0, kUpb_NoSub, 5, kUpb_FieldMode_Scalar | (kUpb_FieldRep_4Byte << kUpb_FieldRep_Shift)},
};

const upb_MiniTable google_protobuf_Duration_msg_init = {
  NULL,
  &google_protobuf_Duration__fields[0],
  16, 2, kUpb_ExtMode_NonExtendable, 2, UPB_FASTTABLE_MASK(24), 0,
  UPB_FASTTABLE_INIT({
    {0x0000000000000000, &_upb_FastDecoder_DecodeGeneric},
    {0x000800003f000008, &upb_psv8_1bt},
    {0x000000003f000010, &upb_psv4_1bt},
    {0x0000000000000000, &_upb_FastDecoder_DecodeGeneric},
  })
};

static const upb_MiniTable *messages_layout[1] = {
  &google_protobuf_Duration_msg_init,
};

const upb_MiniTableFile google_protobuf_duration_proto_upb_file_layout = {
  messages_layout,
  NULL,
  NULL,
  1,
  0,
  0,
};

#include "upb/port/undef.inc"
