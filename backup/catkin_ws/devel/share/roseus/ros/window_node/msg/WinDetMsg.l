;; Auto-generated. Do not edit!


(when (boundp 'window_node::WinDetMsg)
  (if (not (find-package "WINDOW_NODE"))
    (make-package "WINDOW_NODE"))
  (shadow 'WinDetMsg (find-package "WINDOW_NODE")))
(unless (find-package "WINDOW_NODE::WINDETMSG")
  (make-package "WINDOW_NODE::WINDETMSG"))

(in-package "ROS")
;;//! \htmlinclude WinDetMsg.msg.html


(defclass window_node::WinDetMsg
  :super ros::object
  :slots (_delta_x _delta_y _scale _status ))

(defmethod window_node::WinDetMsg
  (:init
   (&key
    ((:delta_x __delta_x) 0)
    ((:delta_y __delta_y) 0)
    ((:scale __scale) 0)
    ((:status __status) 0)
    )
   (send-super :init)
   (setq _delta_x (round __delta_x))
   (setq _delta_y (round __delta_y))
   (setq _scale (round __scale))
   (setq _status (round __status))
   self)
  (:delta_x
   (&optional __delta_x)
   (if __delta_x (setq _delta_x __delta_x)) _delta_x)
  (:delta_y
   (&optional __delta_y)
   (if __delta_y (setq _delta_y __delta_y)) _delta_y)
  (:scale
   (&optional __scale)
   (if __scale (setq _scale __scale)) _scale)
  (:status
   (&optional __status)
   (if __status (setq _status __status)) _status)
  (:serialization-length
   ()
   (+
    ;; int16 _delta_x
    2
    ;; int16 _delta_y
    2
    ;; int16 _scale
    2
    ;; int16 _status
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _delta_x
       (write-word _delta_x s)
     ;; int16 _delta_y
       (write-word _delta_y s)
     ;; int16 _scale
       (write-word _scale s)
     ;; int16 _status
       (write-word _status s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _delta_x
     (setq _delta_x (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _delta_y
     (setq _delta_y (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _scale
     (setq _scale (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _status
     (setq _status (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get window_node::WinDetMsg :md5sum-) "a02cd86d2806c52a7dced0d3efb6c2dd")
(setf (get window_node::WinDetMsg :datatype-) "window_node/WinDetMsg")
(setf (get window_node::WinDetMsg :definition-)
      "int16 delta_x
int16 delta_y
int16 scale
int16 status

")



(provide :window_node/WinDetMsg "a02cd86d2806c52a7dced0d3efb6c2dd")


