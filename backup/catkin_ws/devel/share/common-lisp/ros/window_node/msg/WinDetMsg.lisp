; Auto-generated. Do not edit!


(cl:in-package window_node-msg)


;//! \htmlinclude WinDetMsg.msg.html

(cl:defclass <WinDetMsg> (roslisp-msg-protocol:ros-message)
  ((delta_x
    :reader delta_x
    :initarg :delta_x
    :type cl:fixnum
    :initform 0)
   (delta_y
    :reader delta_y
    :initarg :delta_y
    :type cl:fixnum
    :initform 0)
   (scale
    :reader scale
    :initarg :scale
    :type cl:fixnum
    :initform 0)
   (status
    :reader status
    :initarg :status
    :type cl:fixnum
    :initform 0))
)

(cl:defclass WinDetMsg (<WinDetMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <WinDetMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'WinDetMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name window_node-msg:<WinDetMsg> is deprecated: use window_node-msg:WinDetMsg instead.")))

(cl:ensure-generic-function 'delta_x-val :lambda-list '(m))
(cl:defmethod delta_x-val ((m <WinDetMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader window_node-msg:delta_x-val is deprecated.  Use window_node-msg:delta_x instead.")
  (delta_x m))

(cl:ensure-generic-function 'delta_y-val :lambda-list '(m))
(cl:defmethod delta_y-val ((m <WinDetMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader window_node-msg:delta_y-val is deprecated.  Use window_node-msg:delta_y instead.")
  (delta_y m))

(cl:ensure-generic-function 'scale-val :lambda-list '(m))
(cl:defmethod scale-val ((m <WinDetMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader window_node-msg:scale-val is deprecated.  Use window_node-msg:scale instead.")
  (scale m))

(cl:ensure-generic-function 'status-val :lambda-list '(m))
(cl:defmethod status-val ((m <WinDetMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader window_node-msg:status-val is deprecated.  Use window_node-msg:status instead.")
  (status m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <WinDetMsg>) ostream)
  "Serializes a message object of type '<WinDetMsg>"
  (cl:let* ((signed (cl:slot-value msg 'delta_x)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'delta_y)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'scale)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'status)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <WinDetMsg>) istream)
  "Deserializes a message object of type '<WinDetMsg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'delta_x) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'delta_y) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'scale) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'status) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<WinDetMsg>)))
  "Returns string type for a message object of type '<WinDetMsg>"
  "window_node/WinDetMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'WinDetMsg)))
  "Returns string type for a message object of type 'WinDetMsg"
  "window_node/WinDetMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<WinDetMsg>)))
  "Returns md5sum for a message object of type '<WinDetMsg>"
  "a02cd86d2806c52a7dced0d3efb6c2dd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'WinDetMsg)))
  "Returns md5sum for a message object of type 'WinDetMsg"
  "a02cd86d2806c52a7dced0d3efb6c2dd")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<WinDetMsg>)))
  "Returns full string definition for message of type '<WinDetMsg>"
  (cl:format cl:nil "int16 delta_x~%int16 delta_y~%int16 scale~%int16 status~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'WinDetMsg)))
  "Returns full string definition for message of type 'WinDetMsg"
  (cl:format cl:nil "int16 delta_x~%int16 delta_y~%int16 scale~%int16 status~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <WinDetMsg>))
  (cl:+ 0
     2
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <WinDetMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'WinDetMsg
    (cl:cons ':delta_x (delta_x msg))
    (cl:cons ':delta_y (delta_y msg))
    (cl:cons ':scale (scale msg))
    (cl:cons ':status (status msg))
))
