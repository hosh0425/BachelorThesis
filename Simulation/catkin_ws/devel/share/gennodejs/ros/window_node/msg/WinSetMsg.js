// Auto-generated. Do not edit!

// (in-package window_node.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class WinSetMsg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.data = null;
      this.vmin = null;
      this.vmax = null;
      this.smin = null;
      this.erosion_element = null;
      this.erosion_kernel = null;
      this.dilation_element = null;
      this.dilation_kernel = null;
      this.mode = null;
      this.hist_17 = null;
      this.hist_18 = null;
      this.hist_19 = null;
      this.hist_20 = null;
      this.hist_21 = null;
      this.hist_22 = null;
      this.swich = null;
      this.rst = null;
    }
    else {
      if (initObj.hasOwnProperty('data')) {
        this.data = initObj.data
      }
      else {
        this.data = 0;
      }
      if (initObj.hasOwnProperty('vmin')) {
        this.vmin = initObj.vmin
      }
      else {
        this.vmin = 0;
      }
      if (initObj.hasOwnProperty('vmax')) {
        this.vmax = initObj.vmax
      }
      else {
        this.vmax = 0;
      }
      if (initObj.hasOwnProperty('smin')) {
        this.smin = initObj.smin
      }
      else {
        this.smin = 0;
      }
      if (initObj.hasOwnProperty('erosion_element')) {
        this.erosion_element = initObj.erosion_element
      }
      else {
        this.erosion_element = 0;
      }
      if (initObj.hasOwnProperty('erosion_kernel')) {
        this.erosion_kernel = initObj.erosion_kernel
      }
      else {
        this.erosion_kernel = 0;
      }
      if (initObj.hasOwnProperty('dilation_element')) {
        this.dilation_element = initObj.dilation_element
      }
      else {
        this.dilation_element = 0;
      }
      if (initObj.hasOwnProperty('dilation_kernel')) {
        this.dilation_kernel = initObj.dilation_kernel
      }
      else {
        this.dilation_kernel = 0;
      }
      if (initObj.hasOwnProperty('mode')) {
        this.mode = initObj.mode
      }
      else {
        this.mode = false;
      }
      if (initObj.hasOwnProperty('hist_17')) {
        this.hist_17 = initObj.hist_17
      }
      else {
        this.hist_17 = false;
      }
      if (initObj.hasOwnProperty('hist_18')) {
        this.hist_18 = initObj.hist_18
      }
      else {
        this.hist_18 = false;
      }
      if (initObj.hasOwnProperty('hist_19')) {
        this.hist_19 = initObj.hist_19
      }
      else {
        this.hist_19 = false;
      }
      if (initObj.hasOwnProperty('hist_20')) {
        this.hist_20 = initObj.hist_20
      }
      else {
        this.hist_20 = false;
      }
      if (initObj.hasOwnProperty('hist_21')) {
        this.hist_21 = initObj.hist_21
      }
      else {
        this.hist_21 = false;
      }
      if (initObj.hasOwnProperty('hist_22')) {
        this.hist_22 = initObj.hist_22
      }
      else {
        this.hist_22 = false;
      }
      if (initObj.hasOwnProperty('swich')) {
        this.swich = initObj.swich
      }
      else {
        this.swich = 0;
      }
      if (initObj.hasOwnProperty('rst')) {
        this.rst = initObj.rst
      }
      else {
        this.rst = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type WinSetMsg
    // Serialize message field [data]
    bufferOffset = _serializer.int16(obj.data, buffer, bufferOffset);
    // Serialize message field [vmin]
    bufferOffset = _serializer.int16(obj.vmin, buffer, bufferOffset);
    // Serialize message field [vmax]
    bufferOffset = _serializer.int16(obj.vmax, buffer, bufferOffset);
    // Serialize message field [smin]
    bufferOffset = _serializer.int16(obj.smin, buffer, bufferOffset);
    // Serialize message field [erosion_element]
    bufferOffset = _serializer.int16(obj.erosion_element, buffer, bufferOffset);
    // Serialize message field [erosion_kernel]
    bufferOffset = _serializer.int16(obj.erosion_kernel, buffer, bufferOffset);
    // Serialize message field [dilation_element]
    bufferOffset = _serializer.int16(obj.dilation_element, buffer, bufferOffset);
    // Serialize message field [dilation_kernel]
    bufferOffset = _serializer.int16(obj.dilation_kernel, buffer, bufferOffset);
    // Serialize message field [mode]
    bufferOffset = _serializer.bool(obj.mode, buffer, bufferOffset);
    // Serialize message field [hist_17]
    bufferOffset = _serializer.bool(obj.hist_17, buffer, bufferOffset);
    // Serialize message field [hist_18]
    bufferOffset = _serializer.bool(obj.hist_18, buffer, bufferOffset);
    // Serialize message field [hist_19]
    bufferOffset = _serializer.bool(obj.hist_19, buffer, bufferOffset);
    // Serialize message field [hist_20]
    bufferOffset = _serializer.bool(obj.hist_20, buffer, bufferOffset);
    // Serialize message field [hist_21]
    bufferOffset = _serializer.bool(obj.hist_21, buffer, bufferOffset);
    // Serialize message field [hist_22]
    bufferOffset = _serializer.bool(obj.hist_22, buffer, bufferOffset);
    // Serialize message field [swich]
    bufferOffset = _serializer.int16(obj.swich, buffer, bufferOffset);
    // Serialize message field [rst]
    bufferOffset = _serializer.bool(obj.rst, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type WinSetMsg
    let len;
    let data = new WinSetMsg(null);
    // Deserialize message field [data]
    data.data = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [vmin]
    data.vmin = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [vmax]
    data.vmax = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [smin]
    data.smin = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [erosion_element]
    data.erosion_element = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [erosion_kernel]
    data.erosion_kernel = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [dilation_element]
    data.dilation_element = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [dilation_kernel]
    data.dilation_kernel = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [mode]
    data.mode = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [hist_17]
    data.hist_17 = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [hist_18]
    data.hist_18 = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [hist_19]
    data.hist_19 = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [hist_20]
    data.hist_20 = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [hist_21]
    data.hist_21 = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [hist_22]
    data.hist_22 = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [swich]
    data.swich = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [rst]
    data.rst = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 26;
  }

  static datatype() {
    // Returns string type for a message object
    return 'window_node/WinSetMsg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '894b53f7dd2b583012a43d0582ef5f5a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int16 data
    int16 vmin
    int16 vmax
    int16 smin
    int16 erosion_element
    int16 erosion_kernel
    int16 dilation_element
    int16 dilation_kernel
    bool mode
    bool hist_17
    bool hist_18
    bool hist_19
    bool hist_20
    bool hist_21
    bool hist_22
    int16 swich
    bool rst
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new WinSetMsg(null);
    if (msg.data !== undefined) {
      resolved.data = msg.data;
    }
    else {
      resolved.data = 0
    }

    if (msg.vmin !== undefined) {
      resolved.vmin = msg.vmin;
    }
    else {
      resolved.vmin = 0
    }

    if (msg.vmax !== undefined) {
      resolved.vmax = msg.vmax;
    }
    else {
      resolved.vmax = 0
    }

    if (msg.smin !== undefined) {
      resolved.smin = msg.smin;
    }
    else {
      resolved.smin = 0
    }

    if (msg.erosion_element !== undefined) {
      resolved.erosion_element = msg.erosion_element;
    }
    else {
      resolved.erosion_element = 0
    }

    if (msg.erosion_kernel !== undefined) {
      resolved.erosion_kernel = msg.erosion_kernel;
    }
    else {
      resolved.erosion_kernel = 0
    }

    if (msg.dilation_element !== undefined) {
      resolved.dilation_element = msg.dilation_element;
    }
    else {
      resolved.dilation_element = 0
    }

    if (msg.dilation_kernel !== undefined) {
      resolved.dilation_kernel = msg.dilation_kernel;
    }
    else {
      resolved.dilation_kernel = 0
    }

    if (msg.mode !== undefined) {
      resolved.mode = msg.mode;
    }
    else {
      resolved.mode = false
    }

    if (msg.hist_17 !== undefined) {
      resolved.hist_17 = msg.hist_17;
    }
    else {
      resolved.hist_17 = false
    }

    if (msg.hist_18 !== undefined) {
      resolved.hist_18 = msg.hist_18;
    }
    else {
      resolved.hist_18 = false
    }

    if (msg.hist_19 !== undefined) {
      resolved.hist_19 = msg.hist_19;
    }
    else {
      resolved.hist_19 = false
    }

    if (msg.hist_20 !== undefined) {
      resolved.hist_20 = msg.hist_20;
    }
    else {
      resolved.hist_20 = false
    }

    if (msg.hist_21 !== undefined) {
      resolved.hist_21 = msg.hist_21;
    }
    else {
      resolved.hist_21 = false
    }

    if (msg.hist_22 !== undefined) {
      resolved.hist_22 = msg.hist_22;
    }
    else {
      resolved.hist_22 = false
    }

    if (msg.swich !== undefined) {
      resolved.swich = msg.swich;
    }
    else {
      resolved.swich = 0
    }

    if (msg.rst !== undefined) {
      resolved.rst = msg.rst;
    }
    else {
      resolved.rst = false
    }

    return resolved;
    }
};

module.exports = WinSetMsg;
