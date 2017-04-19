util.d: ../../include/util.h ../../include/rnGen.h ../../include/myUsage.h ../../include/myHashMap.h ../../include/parse.h 
../../include/util.h: util.h
	@rm -f ../../include/util.h
	@ln -fs ../src/util/util.h ../../include/util.h
../../include/rnGen.h: rnGen.h
	@rm -f ../../include/rnGen.h
	@ln -fs ../src/util/rnGen.h ../../include/rnGen.h
../../include/myUsage.h: myUsage.h
	@rm -f ../../include/myUsage.h
	@ln -fs ../src/util/myUsage.h ../../include/myUsage.h
../../include/myHashMap.h: myHashMap.h
	@rm -f ../../include/myHashMap.h
	@ln -fs ../src/util/myHashMap.h ../../include/myHashMap.h
../../include/parse.h: parse.h
	@rm -f ../../include/parse.h
	@ln -fs ../src/util/parse.h ../../include/parse.h
