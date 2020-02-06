;; Auto-generated. Do not edit!


(when (boundp 'window_node::WinSetMsg)
  (if (not (find-package "WINDOW_NODE"))
    (make-package "WINDOW_NODE"))
  (shadow 'WinSetMsg (find-package "WINDOW_NODE")))
(unless (find-package "WINDOW_NODE::WINSETMSG")
  (make-package "WINDOW_NODE::WINSETMSG"))

(in-package "ROS")
;;//! \htmlinclude WinSetMsg.msg.html


(defclass window_node::WinSetMsg
  :super ros::object
  :slots (_data _vmin _vmax _smin _erosion_element _erosion_kernel _dilation_element _dilation_kernel _mode _hist_17 _hist_18 _hist_19 _hist_20 _hist_21 _hist_22 _swich _rst ))

(defmethod window_node::WinSetMsg
  (:init
   (&key
    ((:data __data) 0)
    ((:vmin __vmin) 0)
    ((:vmax __vmax) 0)
    ((:smin __smin) 0)
    ((:erosion_element __erosion_element) 0)
    ((:erosion_kernel __erosion_kernel) 0)
    ((:dilation_element __dilation_element) 0)
    ((:dilation_kernel __dilation_kernel) 0)
    ((:mode __mode) nil)
    ((:hist_17 __hist_17) nil)
    ((:hist_18 __hist_18) nil)
    ((:hist_19 __hist_19) nil)
    ((:hist_20 __hist_20) nil)
    ((:hist_21 __hist_21) nil)
    ((:hist_22 __hist_22) nil)
    ((:swich __swich) 0)
    ((:rst __rst) nil)
    )
   (send-super :init)
   (setq _data (round __data))
   (setq _vmin (round __vmin))
   (setq _vmax (round __vmax))
   (setq _smin (round __smin))
   (setq _erosion_element (round __erosion_element))
   (setq _erosion_kernel (round __erosion_kernel))
   (setq _dilation_element (round __dilation_element))
   (setq _dilation_kernel (round __dilation_kernel))
   (setq _mode __mode)
   (setq _hist_17 __hist_17)
   (setq _hist_18 __hist_18)
   (setq _hist_19 __hist_19)
   (setq _hist_20 __hist_20)
   (setq _hist_21 __hist_21)
   (setq _hist_22 __hist_22)
   (setq _swich (round __swich))
   (setq _rst __rst)
   self)
  (:data
   (&optional __data)
   (if __data (setq _data __data)) _data)
  (:vmin
   (&optional __vmin)
   (if __vmin (setq _vmin __vmin)) _vmin)
  (:vmax
   (&optional __vmax)
   (if __vmax (setq _vmax __vmax)) _vmax)
  (:smin
   (&optional __smin)
   (if __smin (setq _smin __smin)) _smin)
  (:erosion_element
   (&optional __erosion_element)
   (if __erosion_element (setq _erosion_element __erosion_element)) _erosion_element)
  (:erosion_kernel
   (&optional __erosion_kernel)
   (if __erosion_kernel (setq _erosion_kernel __erosion_kernel)) _erosion_kernel)
  (:dilation_element
   (&optional __dilation_element)
   (if __dilation_element (setq _dilation_element __dilation_element)) _dilation_element)
  (:dilation_kernel
   (&optional __dilation_kernel)
   (if __dilation_kernel (setq _dilation_kernel __dilation_kernel)) _dilation_kernel)
  (:mode
   (&optional __mode)
   (if __mode (setq _mode __mode)) _mode)
  (:hist_17
   (&optional __hist_17)
   (if __hist_17 (setq _hist_17 __hist_17)) _hist_17)
  (:hist_18
   (&optional __hist_18)
   (if __hist_18 (setq _hist_18 __hist_18)) _hist_18)
  (:hist_19
   (&optional __hist_19)
   (if __hist_19 (setq _hist_19 __hist_19)) _hist_19)
  (:hist_20
   (&optional __hist_20)
   (if __hist_20 (setq _hist_20 __hist_20)) _hist_20)
  (:hist_21
   (&optional __hist_21)
   (if __hist_21 (setq _hist_21 __hist_21)) _hist_21)
  (:hist_22
   (&optional __hist_22)
   (if __hist_22 (setq _hist_22 __hist_22)) _hist_22)
  (:swich
   (&optional __swich)
   (if __swich (setq _swich __swich)) _swich)
  (:rst
   (&optional __rst)
   (if __rst (setq _rst __rst)) _rst)
  (:serialization-length
   ()
   (+
    ;; int16 _data
    2
    ;; int16 _vmin
    2
    ;; int16 _vmax
    2
    ;; int16 _smin
    2
    ;; int16 _erosion_element
    2
    ;; int16 _erosion_kernel
    2
    ;; int16 _dilation_element
    2
    ;; int16 _dilation_kernel
    2
    ;; bool _mode
    1
    ;; bool _hist_17
    1
    ;; bool _hist_18
    1
    ;; bool _hist_19
    1
    ;; bool _hist_20
    1
    ;; bool _hist_21
    1
    ;; bool _hist_22
    1
    ;; int16 _swich
    2
    ;; bool _rst
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _data
       (write-word _data s)
     ;; int16 _vmin
       (write-word _vmin s)
     ;; int16 _vmax
       (write-word _vmax s)
     ;; int16 _smin
       (write-word _smin s)
     ;; int16 _erosion_element
       (write-word _erosion_element s)
     ;; int16 _erosion_kernel
       (write-word _erosion_kernel s)
     ;; int16 _dilation_element
       (write-word _dilation_element s)
     ;; int16 _dilation_kernel
       (write-word _dilation_kernel s)
     ;; bool _mode
       (if _mode (write-byte -1 s) (write-byte 0 s))
     ;; bool _hist_17
       (if _hist_17 (write-byte -1 s) (write-byte 0 s))
     ;; bool _hist_18
       (if _hist_18 (write-byte -1 s) (write-byte 0 s))
     ;; bool _hist_19
       (if _hist_19 (write-byte -1 s) (write-byte 0 s))
     ;; bool _hist_20
       (if _hist_20 (write-byte -1 s) (write-byte 0 s))
     ;; bool _hist_21
       (if _hist_21 (write-byte -1 s) (write-byte 0 s))
     ;; bool _hist_22
       (if _hist_22 (write-byte -1 s) (write-byte 0 s))
     ;; int16 _swich
       (write-word _swich s)
     ;; bool _rst
       (if _rst (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _data
     (setq _data (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _vmin
     (setq _vmin (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _vmax
     (setq _vmax (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _smin
     (setq _smin (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _erosion_element
     (setq _erosion_element (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _erosion_kernel
     (setq _erosion_kernel (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _dilation_element
     (setq _dilation_element (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _dilation_kernel
     (setq _dilation_kernel (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; bool _mode
     (setq _mode (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _hist_17
     (setq _hist_17 (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _hist_18
     (setq _hist_18 (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _hist_19
     (setq _hist_19 (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _hist_20
     (setq _hist_20 (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _hist_21
     (setq _hist_21 (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _hist_22
     (setq _hist_22 (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; int16 _swich
     (setq _swich (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; bool _rst
     (setq _rst (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get window_node::WinSetMsg :md5sum-) "894b53f7dd2b583012a43d0582ef5f5a")
(setf (get window_node::WinSetMsg :datatype-) "window_node/WinSetMsg")
(setf (get window_node::WinSetMsg :definition-)
      "int16 data
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

")



(provide :window_node/WinSetMsg "894b53f7dd2b583012a43d0582ef5f5a")


