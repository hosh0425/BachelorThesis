
(cl:in-package :asdf)

(defsystem "window_node-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "WinDetMsg" :depends-on ("_package_WinDetMsg"))
    (:file "_package_WinDetMsg" :depends-on ("_package"))
    (:file "WinSetMsg" :depends-on ("_package_WinSetMsg"))
    (:file "_package_WinSetMsg" :depends-on ("_package"))
  ))