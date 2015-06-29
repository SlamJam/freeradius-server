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
void   request__init
                     (Request         *message)
{
  static Request init_value = REQUEST__INIT;
  *message = init_value;
}
size_t request__get_packed_size
                     (const Request *message)
{
  assert(message->base.descriptor == &request__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t request__pack
                     (const Request *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &request__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t request__pack_to_buffer
                     (const Request *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &request__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Request *
       request__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Request *)
     protobuf_c_message_unpack (&request__descriptor,
                                allocator, len, data);
}
void   request__free_unpacked
                     (Request *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &request__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   response__init
                     (Response         *message)
{
  static Response init_value = RESPONSE__INIT;
  *message = init_value;
}
size_t response__get_packed_size
                     (const Response *message)
{
  assert(message->base.descriptor == &response__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t response__pack
                     (const Response *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &response__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t response__pack_to_buffer
                     (const Response *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &response__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Response *
       response__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Response *)
     protobuf_c_message_unpack (&response__descriptor,
                                allocator, len, data);
}
void   response__free_unpacked
                     (Response *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &response__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
char fr__avp__op__default_value[] = ":=";
static const uint32_t fr__avp__vendor__default_value = 0u;
static const ProtobufCFieldDescriptor fr__avp__field_descriptors[5] =
{
  {
    "attr",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(FRAVP, attr),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "vendor",
    2,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_UINT32,
    offsetof(FRAVP, has_vendor),
    offsetof(FRAVP, vendor),
    NULL,
    &fr__avp__vendor__default_value,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "value",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(FRAVP, value),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "op",
    4,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(FRAVP, op),
    NULL,
    &fr__avp__op__default_value,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "tag",
    5,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_UINT32,
    offsetof(FRAVP, has_tag),
    offsetof(FRAVP, tag),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned fr__avp__field_indices_by_name[] = {
  0,   /* field[0] = attr */
  3,   /* field[3] = op */
  4,   /* field[4] = tag */
  2,   /* field[2] = value */
  1,   /* field[1] = vendor */
};
static const ProtobufCIntRange fr__avp__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 5 }
};
const ProtobufCMessageDescriptor fr__avp__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "FR_AVP",
  "FRAVP",
  "FRAVP",
  "",
  sizeof(FRAVP),
  5,
  fr__avp__field_descriptors,
  fr__avp__field_indices_by_name,
  1,  fr__avp__number_ranges,
  (ProtobufCMessageInit) fr__avp__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor request__field_descriptors[11] =
{
  {
    "component",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_ENUM,
    0,   /* quantifier_offset */
    offsetof(Request, component),
    &rlm__component__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "request",
    2,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Request, n_request),
    offsetof(Request, request),
    &fr__avp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "reply",
    3,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Request, n_reply),
    offsetof(Request, reply),
    &fr__avp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "control",
    4,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Request, n_control),
    offsetof(Request, control),
    &fr__avp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "session_state",
    5,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Request, n_session_state),
    offsetof(Request, session_state),
    &fr__avp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "proxy_request",
    6,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Request, n_proxy_request),
    offsetof(Request, proxy_request),
    &fr__avp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "proxy_reply",
    7,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Request, n_proxy_reply),
    offsetof(Request, proxy_reply),
    &fr__avp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "coa",
    8,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Request, n_coa),
    offsetof(Request, coa),
    &fr__avp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "coa_reply",
    9,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Request, n_coa_reply),
    offsetof(Request, coa_reply),
    &fr__avp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "disconnect",
    10,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Request, n_disconnect),
    offsetof(Request, disconnect),
    &fr__avp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "disconnect_reply",
    11,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Request, n_disconnect_reply),
    offsetof(Request, disconnect_reply),
    &fr__avp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned request__field_indices_by_name[] = {
  7,   /* field[7] = coa */
  8,   /* field[8] = coa_reply */
  0,   /* field[0] = component */
  3,   /* field[3] = control */
  9,   /* field[9] = disconnect */
  10,   /* field[10] = disconnect_reply */
  6,   /* field[6] = proxy_reply */
  5,   /* field[5] = proxy_request */
  2,   /* field[2] = reply */
  1,   /* field[1] = request */
  4,   /* field[4] = session_state */
};
static const ProtobufCIntRange request__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 11 }
};
const ProtobufCMessageDescriptor request__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "Request",
  "Request",
  "Request",
  "",
  sizeof(Request),
  11,
  request__field_descriptors,
  request__field_indices_by_name,
  1,  request__number_ranges,
  (ProtobufCMessageInit) request__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const RLMRCODE response__rcode__default_value = RLM__RCODE__NOOP;
static const ProtobufCFieldDescriptor response__field_descriptors[11] =
{
  {
    "rcode",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_ENUM,
    0,   /* quantifier_offset */
    offsetof(Response, rcode),
    &rlm__rcode__descriptor,
    &response__rcode__default_value,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "request",
    2,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Response, n_request),
    offsetof(Response, request),
    &fr__avp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "reply",
    3,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Response, n_reply),
    offsetof(Response, reply),
    &fr__avp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "control",
    4,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Response, n_control),
    offsetof(Response, control),
    &fr__avp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "session_state",
    5,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Response, n_session_state),
    offsetof(Response, session_state),
    &fr__avp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "proxy_request",
    6,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Response, n_proxy_request),
    offsetof(Response, proxy_request),
    &fr__avp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "proxy_reply",
    7,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Response, n_proxy_reply),
    offsetof(Response, proxy_reply),
    &fr__avp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "coa",
    8,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Response, n_coa),
    offsetof(Response, coa),
    &fr__avp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "coa_reply",
    9,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Response, n_coa_reply),
    offsetof(Response, coa_reply),
    &fr__avp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "disconnect",
    10,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Response, n_disconnect),
    offsetof(Response, disconnect),
    &fr__avp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "disconnect_reply",
    11,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Response, n_disconnect_reply),
    offsetof(Response, disconnect_reply),
    &fr__avp__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned response__field_indices_by_name[] = {
  7,   /* field[7] = coa */
  8,   /* field[8] = coa_reply */
  3,   /* field[3] = control */
  9,   /* field[9] = disconnect */
  10,   /* field[10] = disconnect_reply */
  6,   /* field[6] = proxy_reply */
  5,   /* field[5] = proxy_request */
  0,   /* field[0] = rcode */
  2,   /* field[2] = reply */
  1,   /* field[1] = request */
  4,   /* field[4] = session_state */
};
static const ProtobufCIntRange response__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 11 }
};
const ProtobufCMessageDescriptor response__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "Response",
  "Response",
  "Response",
  "",
  sizeof(Response),
  11,
  response__field_descriptors,
  response__field_indices_by_name,
  1,  response__number_ranges,
  (ProtobufCMessageInit) response__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCEnumValue rlm__rcode__enum_values_by_number[11] =
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
static const ProtobufCEnumValueIndex rlm__rcode__enum_values_by_name[11] =
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
static const ProtobufCEnumValue rlm__component__enum_values_by_number[10] =
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
static const ProtobufCEnumValueIndex rlm__component__enum_values_by_name[10] =
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