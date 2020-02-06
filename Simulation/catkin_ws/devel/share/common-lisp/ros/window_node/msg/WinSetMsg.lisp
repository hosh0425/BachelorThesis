; Auto-generated. Do not edit!


(cl:in-package window_node-msg)


;//! \htmlinclude WinSetMsg.msg.html

(cl:defclass <WinSetMsg> (roslisp-msg-protocol:ros-message)
  ((data
    :reader data
    :initarg :data
    :type cl:fixnum
    :initform 0)
   (vmin
    :reader vmin
    :initarg :vmin
    :type cl:fixnum
    :initform 0)
   (vmax
    :reader vmax
    :initarg :vmax
    :type cl:fixnum
    :initform 0)
   (smin
    :reader smin
    :initarg :smin
    :type cl:fixnum
    :initform 0)
   (erosion_element
    :reader erosion_element
    :initarg :erosion_element
    :type cl:fixnum
    :initform 0)
   (erosion_kernel
    :reader erosion_kernel
    :initarg :erosion_kernel
    :type cl:fixnum
    :initform 0)
   (dilation_element
    :reader dilation_element
    :initarg :dilation_element
    :type cl:fixnum
    :initform 0)
   (dilation_kernel
    :reader dilation_kernel
    :initarg :dilation_kernel
    :type cl:fixnum
    :initform 0)
   (mode
    :reader mode
    :initarg :mode
    :type cl:boolean
    :initform cl:nil)
   (hist_17
    :reader hist_17
    :initarg :hist_17
    :type cl:boolean
    :initform cl:nil)
   (hist_18
    :reader hist_18
    :initarg :hist_18
    :type cl:boolean
    :initform cl:nil)
   (hist_19
    :reader hist_19
    :initarg :hist_19
    :type cl:boolean
    :initform cl:nil)
   (hist_20
    :reader hist_20
    :initarg :hist_20
    :type cl:boolean
    :initform cl:nil)
   (hist_21
    :reader hist_21
    :initarg :hist_21
    :type cl:boolean
    :initform cl:nil)
   (hist_22
    :reader hist_22
    :initarg :hist_22
    :type cl:boolean
    :initform cl:nil)
   (swich
    :reader swich
    :initarg :swich
    :type cl:fixnum
    :initform 0)
   (rst
    :reader rst
    :initarg :rst
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass WinSetMsg (<WinSetMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <WinSetMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'WinSetMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name window_node-msg:<WinSetMsg> is deprecated: use window_node-msg:WinSetMsg instead.")))

(cl:ensure-generic-function 'data-val :lambda-list '(m))
(cl:defmethod data-val ((m <WinSetMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader window_node-msg:data-val is deprecated.  Use window_node-msg:data instead.")
  (data m))

(cl:ensure-generic-function 'vmin-val :lambda-list '(m))
(cl:defmethod vmin-val ((m <WinSetMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader window_node-msg:vmin-val is deprecated.  Use window_node-msg:vmin instead.")
  (vmin m))

(cl:ensure-generic-function 'vmax-val :lambda-list '(m))
(cl:defmethod vmax-val ((m <WinSetMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader window_node-msg:vmax-val is deprecated.  Use window_node-msg:vmax instead.")
  (vmax m))

(cl:ensure-generic-function 'smin-val :lambda-list '(m))
(cl:defmethod smin-val ((m <WinSetMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader window_node-msg:smin-val is deprecated.  Use window_node-msg:smin instead.")
  (smin m))

(cl:ensure-generic-function 'erosion_element-val :lambda-list '(m))
(cl:defmethod erosion_element-val ((m <WinSetMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader window_node-msg:erosion_element-val is deprecated.  Use window_node-msg:erosion_element instead.")
  (erosion_element m))

(cl:ensure-generic-function 'erosion_kernel-val :lambda-list '(m))
(cl:defmethod erosion_kernel-val ((m <WinSetMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader window_node-msg:erosion_kernel-val is deprecated.  Use window_node-msg:erosion_kernel instead.")
  (erosion_kernel m))

(cl:ensure-generic-function 'dilation_element-val :lambda-list '(m))
(cl:defmethod dilation_element-val ((m <WinSetMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader window_node-msg:dilation_element-val is deprecated.  Use window_node-msg:dilation_element instead.")
  (dilation_element m))

(cl:ensure-generic-function 'dilation_kernel-val :lambda-list '(m))
(cl:defmethod dilation_kernel-val ((m <WinSetMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader window_node-msg:dilation_kernel-val is deprecated.  Use window_node-msg:dilation_kernel instead.")
  (dilation_kernel m))

(cl:ensure-generic-function 'mode-val :lambda-list '(m))
(cl:defmethod mode-val ((m <WinSetMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader window_node-msg:mode-val is deprecated.  Use window_node-msg:mode instead.")
  (mode m))

(cl:ensure-generic-function 'hist_17-val :lambda-list '(m))
(cl:defmethod hist_17-val ((m <WinSetMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader window_node-msg:hist_17-val is deprecated.  Use window_node-msg:hist_17 instead.")
  (hist_17 m))

(cl:ensure-generic-function 'hist_18-val :lambda-list '(m))
(cl:defmethod hist_18-val ((m <WinSetMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader window_node-msg:hist_18-val is deprecated.  Use window_node-msg:hist_18 instead.")
  (hist_18 m))

(cl:ensure-generic-function 'hist_19-val :lambda-list '(m))
(cl:defmethod hist_19-val ((m <WinSetMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader window_node-msg:hist_19-val is deprecated.  Use window_node-msg:hist_19 instead.")
  (hist_19 m))

(cl:ensure-generic-function 'hist_20-val :lambda-list '(m))
(cl:defmethod hist_20-val ((m <WinSetMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader window_node-msg:hist_20-val is deprecated.  Use window_node-msg:hist_20 instead.")
  (hist_20 m))

(cl:ensure-generic-function 'hist_21-val :lambda-list '(m))
(cl:defmethod hist_21-val ((m <WinSetMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader window_node-msg:hist_21-val is deprecated.  Use window_node-msg:hist_21 instead.")
  (hist_21 m))

(cl:ensure-generic-function 'hist_22-val :lambda-list '(m))
(cl:defmethod hist_22-val ((m <WinSetMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader window_node-msg:hist_22-val is deprecated.  Use window_node-msg:hist_22 instead.")
  (hist_22 m))

(cl:ensure-generic-function 'swich-val :lambda-list '(m))
(cl:defmethod swich-val ((m <WinSetMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader window_node-msg:swich-val is deprecated.  Use window_node-msg:swich instead.")
  (swich m))

(cl:ensure-generic-function 'rst-val :lambda-list '(m))
(cl:defmethod rst-val ((m <WinSetMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader window_node-msg:rst-val is deprecated.  Use window_node-msg:rst instead.")
  (rst m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <WinSetMsg>) ostream)
  "Serializes a message object of type '<WinSetMsg>"
  (cl:let* ((signed (cl:slot-value msg 'data)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'vmin)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'vmax)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'smin)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'erosion_element)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'erosion_kernel)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'dilation_element)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'dilation_kernel)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'mode) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'hist_17) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'hist_18) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'hist_19) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'hist_20) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'hist_21) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'hist_22) 1 0)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'swich)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'rst) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <WinSetMsg>) istream)
  "Deserializes a message object of type '<WinSetMsg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'data) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'vmin) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'vmax) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'smin) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'erosion_element) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'erosion_kernel) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'dilation_element) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'dilation_kernel) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:setf (cl:slot-value msg 'mode) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'hist_17) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'hist_18) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'hist_19) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'hist_20) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'hist_21) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'hist_22) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'swich) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:setf (cl:slot-value msg 'rst) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<WinSetMsg>)))
  "Returns string type for a message object of type '<WinSetMsg>"
  "window_node/WinSetMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'WinSetMsg)))
  "Returns string type for a message object of type 'WinSetMsg"
  "window_node/WinSetMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<WinSetMsg>)))
  "Returns md5sum for a message object of type '<WinSetMsg>"
  "894b53f7dd2b583012a43d0582ef5f5a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'WinSetMsg)))
  "Returns md5sum for a message object of type 'WinSetMsg"
  "894b53f7dd2b583012a43d0582ef5f5a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<WinSetMsg>)))
  "Returns full string definition for message of type '<WinSetMsg>"
  (cl:format cl:nil "int16 data~%int16 vmin~%int16 vmax~%int16 smin~%int16 erosion_element~%int16 erosion_kernel~%int16 dilation_element~%int16 dilation_kernel~%bool mode~%bool hist_17~%bool hist_18~%bool hist_19~%bool hist_20~%bool hist_21~%bool hist_22~%int16 swich~%bool rst~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'WinSetMsg)))
  "Returns full string definition for message of type 'WinSetMsg"
  (cl:format cl:nil "int16 data~%int16 vmin~%int16 vmax~%int16 smin~%int16 erosion_element~%int16 erosion_kernel~%int16 dilation_element~%int16 dilation_kernel~%bool mode~%bool hist_17~%bool hist_18~%bool hist_19~%bool hist_20~%bool hist_21~%bool hist_22~%int16 swich~%bool rst~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <WinSetMsg>))
  (cl:+ 0
     2
     2
     2
     2
     2
     2
     2
     2
     1
     1
     1
     1
     1
     1
     1
     2
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <WinSetMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'WinSetMsg
    (cl:cons ':data (data msg))
    (cl:cons ':vmin (vmin msg))
    (cl:cons ':vmax (vmax msg))
    (cl:cons ':smin (smin msg))
    (cl:cons ':erosion_element (erosion_element msg))
    (cl:cons ':erosion_kernel (erosion_kernel msg))
    (cl:cons ':dilation_element (dilation_element msg))
    (cl:cons ':dilation_kernel (dilation_kernel msg))
    (cl:cons ':mode (mode msg))
    (cl:cons ':hist_17 (hist_17 msg))
    (cl:cons ':hist_18 (hist_18 msg))
    (cl:cons ':hist_19 (hist_19 msg))
    (cl:cons ':hist_20 (hist_20 msg))
    (cl:cons ':hist_21 (hist_21 msg))
    (cl:cons ':hist_22 (hist_22 msg))
    (cl:cons ':swich (swich msg))
    (cl:cons ':rst (rst msg))
))
