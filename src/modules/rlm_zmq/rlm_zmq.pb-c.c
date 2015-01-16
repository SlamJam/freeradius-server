/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: rlm_zmq.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "rlm_zmq.pb-c.h"
void   fr__avp__init
                     (FRAVP         *message)
{
  static FRAVP init_value = FR__AVP__INIT;
  *message = init_value;
}
size_t fr__avp__get_packed_size
                     (const FRAVP *message)
{
  assert(message->base.descriptor == &fr__avp__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t fr__avp__pack
                     (const FRAVP *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &fr__avp__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t fr__avp__pack_to_buffer
                     (const FRAVP *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &fr__avp__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
FRAVP *
       fr__avp__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (FRAVP *)
     protobuf_c_message_unpack (&fr__avp__descriptor,
                                allocator, len, data);
}
void   fr__avp__free_unpacked
                     (FRAVP *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &fr__avp__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   fr__packet__init
                     (FRPacket         *message)
{
  static FRPacket init_value = FR__PACKET__INIT;
  *message = init_value;
}
size_t fr__packet__get_packed_size
                     (const FRPacket *message)
{
  assert(message->base.descriptor == &fr__packet__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t fr__packet__pack
                     (const FRPacket *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &fr__packet__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t fr__packet__pack_to_buffer
                     (const FRPacket *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &fr__packet__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
FRPacket *
       fr__packet__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (FRPacket *)
     protobuf_c_message_unpack (&fr__packet__descriptor,
                                allocator, len, data);
}
void   fr__packet__free_unpacked
                     (FRPacket *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &fr__packet__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   fr__request__init
                     (FRRequest         *message)
{
  static FRRequest init_value = FR__REQUEST__INIT;
  *message = init_value;
}
size_t fr__request__get_packed_size
                     (const FRRequest *message)
{
  assert(message->base.descriptor == &fr__request__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t fr__request__pack
                     (const FRRequest *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &fr__request__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t fr__request__pack_to_buffer
                     (const FRRequest *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &fr__request__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
FRRequest *
       fr__request__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (FRRequest *)
     protobuf_c_message_unpack (&fr__request__descriptor,
                                allocator, len, data);
}
void   fr__request__free_unpacked
                     (FRRequest *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &fr__request__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   mod__state__init
                     (ModState         *message)
{
  static ModState init_value = MOD__STATE__INIT;
  *message = init_value;
}
size_t mod__state__get_packed_size
                     (const ModState *message)
{
  assert(message->base.descriptor == &mod__state__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t mod__state__pack
                     (const ModState *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &mod__state__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t mod__state__pack_to_buffer
                     (const ModState *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &mod__state__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
ModState *
       mod__state__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (ModState *)
     protobuf_c_message_unpack (&mod__state__descriptor,
                                allocator, len, data);
}
void   mod__state__free_unpacked
                     (ModState *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &mod__state__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor fr__avp__field_descriptors[1] =
{
  {
    "code",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(FRAVP, code),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned fr__avp__field_indices_by_name[] = {
  0,   /* field[0] = code */
};
static const ProtobufCIntRange fr__avp__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor fr__avp__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "FR_AVP",
  "FRAVP",
  "FRAVP",
  "",
  sizeof(FRAVP),
  1,
  fr__avp__field_descriptors,
  fr__avp__field_indices_by_name,
  1,  fr__avp__number_ranges,
  (ProtobufCMessageInit) fr__avp__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor fr__packet__field_descriptors[3] =
{
  {
    "code",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(FRPacket, code),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "id",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(FRPacket, id),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "attrs",
    3,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(FRPacket, n_attrs),
    offsetof(FRPacket, attrs),
    &fr__avp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned fr__packet__field_indices_by_name[] = {
  2,   /* field[2] = attrs */
  0,   /* field[0] = code */
  1,   /* field[1] = id */
};
static const ProtobufCIntRange fr__packet__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor fr__packet__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "FR_Packet",
  "FRPacket",
  "FRPacket",
  "",
  sizeof(FRPacket),
  3,
  fr__packet__field_descriptors,
  fr__packet__field_indices_by_name,
  1,  fr__packet__number_ranges,
  (ProtobufCMessageInit) fr__packet__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor fr__request__field_descriptors[4] =
{
  {
    "packet",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(FRRequest, packet),
    &fr__packet__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "reply",
    2,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(FRRequest, reply),
    &fr__packet__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "config_items",
    3,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(FRRequest, n_config_items),
    offsetof(FRRequest, config_items),
    &fr__avp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "state",
    4,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(FRRequest, n_state),
    offsetof(FRRequest, state),
    &fr__avp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned fr__request__field_indices_by_name[] = {
  2,   /* field[2] = config_items */
  0,   /* field[0] = packet */
  1,   /* field[1] = reply */
  3,   /* field[3] = state */
};
static const ProtobufCIntRange fr__request__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 4 }
};
const ProtobufCMessageDescriptor fr__request__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "FR_Request",
  "FRRequest",
  "FRRequest",
  "",
  sizeof(FRRequest),
  4,
  fr__request__field_descriptors,
  fr__request__field_indices_by_name,
  1,  fr__request__number_ranges,
  (ProtobufCMessageInit) fr__request__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const RLMRCODE mod__state__rcode__default_value = RLM__RCODE__NOOP;
static const ProtobufCFieldDescriptor mod__state__field_descriptors[4] =
{
  {
    "component",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_ENUM,
    0,   /* quantifier_offset */
    offsetof(ModState, component),
    &rlm__component__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "request",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(ModState, request),
    &fr__request__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "prev_rcode",
    3,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_ENUM,
    offsetof(ModState, has_prev_rcode),
    offsetof(ModState, prev_rcode),
    &rlm__rcode__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "rcode",
    4,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_ENUM,
    0,   /* quantifier_offset */
    offsetof(ModState, rcode),
    &rlm__rcode__descriptor,
    &mod__state__rcode__default_value,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned mod__state__field_indices_by_name[] = {
  0,   /* field[0] = component */
  2,   /* field[2] = prev_rcode */
  3,   /* field[3] = rcode */
  1,   /* field[1] = request */
};
static const ProtobufCIntRange mod__state__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 4 }
};
const ProtobufCMessageDescriptor mod__state__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "Mod_State",
  "ModState",
  "ModState",
  "",
  sizeof(ModState),
  4,
  mod__state__field_descriptors,
  mod__state__field_indices_by_name,
  1,  mod__state__number_ranges,
  (ProtobufCMessageInit) mod__state__init,
  NULL,NULL,NULL    /* reserved[123] */
};
const ProtobufCEnumValue rlm__rcode__enum_values_by_number[11] =
{
  { "REJECT", "RLM__RCODE__REJECT", 0 },
  { "FAIL", "RLM__RCODE__FAIL", 1 },
  { "OK", "RLM__RCODE__OK", 2 },
  { "HANDLED", "RLM__RCODE__HANDLED", 3 },
  { "INVALID", "RLM__RCODE__INVALID", 4 },
  { "USERLOCK", "RLM__RCODE__USERLOCK", 5 },
  { "NOTFOUND", "RLM__RCODE__NOTFOUND", 6 },
  { "NOOP", "RLM__RCODE__NOOP", 7 },
  { "UPDATED", "RLM__RCODE__UPDATED", 8 },
  { "NUMCODES", "RLM__RCODE__NUMCODES", 9 },
  { "UNKNOWN", "RLM__RCODE__UNKNOWN", 10 },
};
static const ProtobufCIntRange rlm__rcode__value_ranges[] = {
{0, 0},{0, 11}
};
const ProtobufCEnumValueIndex rlm__rcode__enum_values_by_name[11] =
{
  { "FAIL", 1 },
  { "HANDLED", 3 },
  { "INVALID", 4 },
  { "NOOP", 7 },
  { "NOTFOUND", 6 },
  { "NUMCODES", 9 },
  { "OK", 2 },
  { "REJECT", 0 },
  { "UNKNOWN", 10 },
  { "UPDATED", 8 },
  { "USERLOCK", 5 },
};
const ProtobufCEnumDescriptor rlm__rcode__descriptor =
{
  PROTOBUF_C__ENUM_DESCRIPTOR_MAGIC,
  "RLM_RCODE",
  "RLM_RCODE",
  "RLMRCODE",
  "",
  11,
  rlm__rcode__enum_values_by_number,
  11,
  rlm__rcode__enum_values_by_name,
  1,
  rlm__rcode__value_ranges,
  NULL,NULL,NULL,NULL   /* reserved[1234] */
};
const ProtobufCEnumValue rlm__component__enum_values_by_number[10] =
{
  { "AUTH", "RLM__COMPONENT__AUTH", 0 },
  { "AUTZ", "RLM__COMPONENT__AUTZ", 1 },
  { "PREACCT", "RLM__COMPONENT__PREACCT", 2 },
  { "ACCT", "RLM__COMPONENT__ACCT", 3 },
  { "SESS", "RLM__COMPONENT__SESS", 4 },
  { "PRE_PROXY", "RLM__COMPONENT__PRE_PROXY", 5 },
  { "POST_PROXY", "RLM__COMPONENT__POST_PROXY", 6 },
  { "POST_AUTH", "RLM__COMPONENT__POST_AUTH", 7 },
  { "RECV_COA", "RLM__COMPONENT__RECV_COA", 8 },
  { "SEND_COA", "RLM__COMPONENT__SEND_COA", 9 },
};
static const ProtobufCIntRange rlm__component__value_ranges[] = {
{0, 0},{0, 10}
};
const ProtobufCEnumValueIndex rlm__component__enum_values_by_name[10] =
{
  { "ACCT", 3 },
  { "AUTH", 0 },
  { "AUTZ", 1 },
  { "POST_AUTH", 7 },
  { "POST_PROXY", 6 },
  { "PREACCT", 2 },
  { "PRE_PROXY", 5 },
  { "RECV_COA", 8 },
  { "SEND_COA", 9 },
  { "SESS", 4 },
};
const ProtobufCEnumDescriptor rlm__component__descriptor =
{
  PROTOBUF_C__ENUM_DESCRIPTOR_MAGIC,
  "RLM_COMPONENT",
  "RLM_COMPONENT",
  "RLMCOMPONENT",
  "",
  10,
  rlm__component__enum_values_by_number,
  10,
  rlm__component__enum_values_by_name,
  1,
  rlm__component__value_ranges,
  NULL,NULL,NULL,NULL   /* reserved[1234] */
};
