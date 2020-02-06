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

class WinDetMsg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.delta_x = null;
      this.delta_y = null;
      this.scale = null;
      this.status = null;
    }
    else {
      if (initObj.hasOwnProperty('delta_x')) {
        this.delta_x = initObj.delta_x
      }
      else {
        this.delta_x = 0;
      }
      if (initObj.hasOwnProperty('delta_y')) {
        this.delta_y = initObj.delta_y
      }
      else {
        this.delta_y = 0;
      }
      if (initObj.hasOwnProperty('scale')) {
        this.scale = initObj.scale
      }
      else {
        this.scale = 0;
      }
      if (initObj.hasOwnProperty('status')) {
        this.status = initObj.status
      }
      else {
        this.status = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type WinDetMsg
    // Serialize message field [delta_x]
    bufferOffset = _serializer.int16(obj.delta_x, buffer, bufferOffset);
    // Serialize message field [delta_y]
    bufferOffset = _serializer.int16(obj.delta_y, buffer, bufferOffset);
    // Serialize message field [scale]
    bufferOffset = _serializer.int16(obj.scale, buffer, bufferOffset);
    // Serialize message field [status]
    bufferOffset = _serializer.int16(obj.status, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type WinDetMsg
    let len;
    let data = new WinDetMsg(null);
    // Deserialize message field [delta_x]
    data.delta_x = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [delta_y]
    data.delta_y = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [scale]
    data.scale = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [status]
    data.status = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'window_node/WinDetMsg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a02cd86d2806c52a7dced0d3efb6c2dd';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int16 delta_x
    int16 delta_y
    int16 scale
    int16 status
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new WinDetMsg(null);
    if (msg.delta_x !== undefined) {
      resolved.delta_x = msg.delta_x;
    }
    else {
      resolved.delta_x = 0
    }

    if (msg.delta_y !== undefined) {
      resolved.delta_y = msg.delta_y;
    }
    else {
      resolved.delta_y = 0
    }

    if (msg.scale !== undefined) {
      resolved.scale = msg.scale;
    }
    else {
      resolved.scale = 0
    }

    if (msg.status !== undefined) {
      resolved.status = msg.status;
    }
    else {
      resolved.status = 0
    }

    return resolved;
    }
};

module.exports = WinDetMsg;
