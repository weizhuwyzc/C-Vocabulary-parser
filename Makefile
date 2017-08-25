#COMAKE2 edit-mode: -*- Makefile -*-
####################64Bit Mode####################
ifeq ($(shell uname -m),x86_64)
CC=gcc
CXX=g++
CXXFLAGS=-g \
  -pipe \
  -W \
  -Wall \
  -fPIC
CFLAGS=-g \
  -pipe \
  -W \
  -Wall \
  -fPIC
CPPFLAGS=-D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION="1.9.8.7"
INCPATH=-I. \
  -I./dict_parser \
  -I./output/include
DEP_INCPATH=-I../../../lib2-64/ullib \
  -I../../../lib2-64/ullib/include \
  -I../../../lib2-64/ullib/output \
  -I../../../lib2-64/ullib/output/include \
  -I../../../third-64/gtest \
  -I../../../third-64/gtest/include \
  -I../../../third-64/gtest/output \
  -I../../../third-64/gtest/output/include

#============ CCP vars ============
CCHECK=@ccheck.py
CCHECK_FLAGS=
PCLINT=@pclint
PCLINT_FLAGS=
CCP=@ccp.py
CCP_FLAGS=


#COMAKE UUID
COMAKE_MD5=f9a07ca69e1e8bf93ee6424e9ff562ae  COMAKE


.PHONY:all
all:comake2_makefile_check dict_parser_tool libdict_parser.a output test/buildin_data_test 
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mall[0m']"
	@echo "make all done"

.PHONY:comake2_makefile_check
comake2_makefile_check:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mcomake2_makefile_check[0m']"
	#in case of error, update 'Makefile' by 'comake2'
	@echo "$(COMAKE_MD5)">comake2.md5
	@md5sum -c --status comake2.md5
	@rm -f comake2.md5

.PHONY:ccpclean
ccpclean:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mccpclean[0m']"
	@echo "make ccpclean done"

.PHONY:clean
clean:ccpclean
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mclean[0m']"
	rm -rf dict_parser_tool
	rm -rf ./output/bin/dict_parser_tool
	rm -rf libdict_parser.a
	rm -rf ./output/lib/libdict_parser.a
	rm -rf ./output/include/buildin_data.h
	rm -rf ./output/include/data_type.h
	rm -rf ./output/include/define_func.h
	rm -rf ./output/include/dict_parser.h
	rm -rf ./output/include/idata.h
	rm -rf ./output/include/user_data.h
	rm -rf output
	rm -rf test/buildin_data_test
	rm -rf ./output/bin/buildin_data_test
	rm -rf dict_parser/dict_parser_tool_buildin_data.o
	rm -rf dict_parser/dict_parser_tool_dict_parser.o
	rm -rf dict_parser/dict_parser_tool_user_data.o
	rm -rf dict_parser_tool_main.o
	rm -rf dict_parser/dict_parser_buildin_data.o
	rm -rf dict_parser/dict_parser_dict_parser.o
	rm -rf dict_parser/dict_parser_user_data.o
	rm -rf dict_parser_main.o
	rm -rf test/buildin_data_test_buildin_data_test.o

.PHONY:dist
dist:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdist[0m']"
	tar czvf output.tar.gz output
	@echo "make dist done"

.PHONY:distclean
distclean:clean
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdistclean[0m']"
	rm -f output.tar.gz
	@echo "make distclean done"

.PHONY:love
love:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mlove[0m']"
	@echo "make love done"

dict_parser_tool:dict_parser/dict_parser_tool_buildin_data.o \
  dict_parser/dict_parser_tool_dict_parser.o \
  dict_parser/dict_parser_tool_user_data.o \
  dict_parser_tool_main.o
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdict_parser_tool[0m']"
	$(CXX) dict_parser/dict_parser_tool_buildin_data.o \
  dict_parser/dict_parser_tool_dict_parser.o \
  dict_parser/dict_parser_tool_user_data.o \
  dict_parser_tool_main.o -Xlinker "-("  ../../../lib2-64/ullib/lib/libullib.a \
  ../../../third-64/gtest/lib/libgtest.a \
  ../../../third-64/gtest/lib/libgtest_main.a -lpthread \
  -lcrypto \
  -lrt -Xlinker "-)" -o dict_parser_tool
	mkdir -p ./output/bin
	cp -f --link dict_parser_tool ./output/bin

libdict_parser.a:dict_parser/dict_parser_buildin_data.o \
  dict_parser/dict_parser_dict_parser.o \
  dict_parser/dict_parser_user_data.o \
  dict_parser_main.o \
  dict_parser/buildin_data.h \
  dict_parser/data_type.h \
  dict_parser/define_func.h \
  dict_parser/dict_parser.h \
  dict_parser/idata.h \
  dict_parser/user_data.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mlibdict_parser.a[0m']"
	ar crs libdict_parser.a dict_parser/dict_parser_buildin_data.o \
  dict_parser/dict_parser_dict_parser.o \
  dict_parser/dict_parser_user_data.o \
  dict_parser_main.o
	mkdir -p ./output/lib
	cp -f --link libdict_parser.a ./output/lib
	mkdir -p ./output/include
	cp -f --link dict_parser/buildin_data.h dict_parser/data_type.h dict_parser/define_func.h dict_parser/dict_parser.h dict_parser/idata.h dict_parser/user_data.h ./output/include

output:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40moutput[0m']"
	echo "build output over"

test/buildin_data_test:test/buildin_data_test_buildin_data_test.o \
  ./output/lib/libdict_parser.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest/buildin_data_test[0m']"
	$(CXX) test/buildin_data_test_buildin_data_test.o -Xlinker "-(" ./output/lib/libdict_parser.a ../../../lib2-64/ullib/lib/libullib.a \
  ../../../third-64/gtest/lib/libgtest.a \
  ../../../third-64/gtest/lib/libgtest_main.a -lpthread \
  -lcrypto \
  -lrt -Xlinker "-)" -o test/buildin_data_test
	mkdir -p ./output/bin
	cp -f --link test/buildin_data_test ./output/bin

dict_parser/dict_parser_tool_buildin_data.o:dict_parser/buildin_data.cpp \
  dict_parser/buildin_data.h \
  dict_parser/idata.h \
  dict_parser/data_type.h \
  dict_parser/define_func.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdict_parser/dict_parser_tool_buildin_data.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o dict_parser/dict_parser_tool_buildin_data.o dict_parser/buildin_data.cpp

dict_parser/dict_parser_tool_dict_parser.o:dict_parser/dict_parser.cpp \
  dict_parser/dict_parser.h \
  dict_parser/idata.h \
  dict_parser/data_type.h \
  dict_parser/user_data.h \
  dict_parser/buildin_data.h \
  dict_parser/define_func.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdict_parser/dict_parser_tool_dict_parser.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o dict_parser/dict_parser_tool_dict_parser.o dict_parser/dict_parser.cpp

dict_parser/dict_parser_tool_user_data.o:dict_parser/user_data.cpp \
  dict_parser/user_data.h \
  dict_parser/idata.h \
  dict_parser/data_type.h \
  dict_parser/buildin_data.h \
  dict_parser/define_func.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdict_parser/dict_parser_tool_user_data.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o dict_parser/dict_parser_tool_user_data.o dict_parser/user_data.cpp

dict_parser_tool_main.o:main.cpp \
  dict_parser/dict_parser.h \
  dict_parser/idata.h \
  dict_parser/data_type.h \
  dict_parser/user_data.h \
  dict_parser/buildin_data.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdict_parser_tool_main.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o dict_parser_tool_main.o main.cpp

dict_parser/dict_parser_buildin_data.o:dict_parser/buildin_data.cpp \
  dict_parser/buildin_data.h \
  dict_parser/idata.h \
  dict_parser/data_type.h \
  dict_parser/define_func.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdict_parser/dict_parser_buildin_data.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_UNIT_TEST_ \
  -Dprivate=public \
  -Dprotected=public $(CXXFLAGS)  -o dict_parser/dict_parser_buildin_data.o dict_parser/buildin_data.cpp

dict_parser/dict_parser_dict_parser.o:dict_parser/dict_parser.cpp \
  dict_parser/dict_parser.h \
  dict_parser/idata.h \
  dict_parser/data_type.h \
  dict_parser/user_data.h \
  dict_parser/buildin_data.h \
  dict_parser/define_func.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdict_parser/dict_parser_dict_parser.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_UNIT_TEST_ \
  -Dprivate=public \
  -Dprotected=public $(CXXFLAGS)  -o dict_parser/dict_parser_dict_parser.o dict_parser/dict_parser.cpp

dict_parser/dict_parser_user_data.o:dict_parser/user_data.cpp \
  dict_parser/user_data.h \
  dict_parser/idata.h \
  dict_parser/data_type.h \
  dict_parser/buildin_data.h \
  dict_parser/define_func.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdict_parser/dict_parser_user_data.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_UNIT_TEST_ \
  -Dprivate=public \
  -Dprotected=public $(CXXFLAGS)  -o dict_parser/dict_parser_user_data.o dict_parser/user_data.cpp

dict_parser_main.o:main.cpp \
  dict_parser/dict_parser.h \
  dict_parser/idata.h \
  dict_parser/data_type.h \
  dict_parser/user_data.h \
  dict_parser/buildin_data.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdict_parser_main.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_UNIT_TEST_ \
  -Dprivate=public \
  -Dprotected=public $(CXXFLAGS)  -o dict_parser_main.o main.cpp

test/buildin_data_test_buildin_data_test.o:test/buildin_data_test.cpp \
  dict_parser/buildin_data.h \
  dict_parser/idata.h \
  dict_parser/data_type.h \
  dict_parser/idata.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest/buildin_data_test_buildin_data_test.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D__INLINE__="" \
  -Dprivate=public \
  -Dprotected=public \
  -D__64BIT__ $(CXXFLAGS)  -o test/buildin_data_test_buildin_data_test.o test/buildin_data_test.cpp

endif #ifeq ($(shell uname -m),x86_64)


