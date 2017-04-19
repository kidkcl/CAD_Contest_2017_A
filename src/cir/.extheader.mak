cir.d: ../../include/cirDef.h ../../include/cirGate.h ../../include/cirMgr.h ../../include/cirMiter.h 
../../include/cirDef.h: cirDef.h
	@rm -f ../../include/cirDef.h
	@ln -fs ../src/cir/cirDef.h ../../include/cirDef.h
../../include/cirGate.h: cirGate.h
	@rm -f ../../include/cirGate.h
	@ln -fs ../src/cir/cirGate.h ../../include/cirGate.h
../../include/cirMgr.h: cirMgr.h
	@rm -f ../../include/cirMgr.h
	@ln -fs ../src/cir/cirMgr.h ../../include/cirMgr.h
../../include/cirMiter.h: cirMiter.h
	@rm -f ../../include/cirMiter.h
	@ln -fs ../src/cir/cirMiter.h ../../include/cirMiter.h
