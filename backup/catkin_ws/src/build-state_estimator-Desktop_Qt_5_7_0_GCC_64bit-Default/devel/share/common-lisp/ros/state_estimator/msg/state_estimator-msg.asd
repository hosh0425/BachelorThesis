
(cl:in-package :asdf)

(defsystem "state_estimator-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "Ardrone3PilotingStateAttitudeChanged" :depends-on ("_package_Ardrone3PilotingStateAttitudeChanged"))
    (:file "_package_Ardrone3PilotingStateAttitudeChanged" :depends-on ("_package"))
    (:file "Ardrone3PilotingStateSpeedChanged" :depends-on ("_package_Ardrone3PilotingStateSpeedChanged"))
    (:file "_package_Ardrone3PilotingStateSpeedChanged" :depends-on ("_package"))
  ))