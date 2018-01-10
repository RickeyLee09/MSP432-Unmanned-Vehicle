# invoke SourceDir generated makefile for Robot.pem4f
Robot.pem4f: .libraries,Robot.pem4f
.libraries,Robot.pem4f: package/cfg/Robot_pem4f.xdl
	$(MAKE) -f C:\Users\shailes\ONEDRI~1\Teaching\MScRobotics\Code\CSRobot\2017\CSRobot_01_2017/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\shailes\ONEDRI~1\Teaching\MScRobotics\Code\CSRobot\2017\CSRobot_01_2017/src/makefile.libs clean

