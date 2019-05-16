
TRACER_HOME=/home/nvm/Documents/Tracer-malloc
LLVM_HOME=/home/nvm/llvm-3.4/llvm_build

export WORKLOAD=triad,my_print,main

${TRACER_HOME}/build/ast-pass/get-labeled-stmts *.c -- -I${LLVM_HOME}/lib/clang/3.4/include

echo "generate *.llvm and *-opt.llvm file"

clang -g -O3 -S -emit-llvm -o tracer.ll triad.c

opt -S -load=${TRACER_HOME}/build/full-trace/full_trace.so -fulltrace -labelmapwriter -trace-all-callees <tracer.ll> tracer-opt.ll

clang tracer-opt.ll ../../profile-func/trace_logger.c -o print.o -lz
