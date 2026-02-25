#include "mlir/IR/AsmState.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/Parser/Parser.h"
#include "mlir/Support/FileUtilities.h"

#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "llvm/Support/raw_ostream.h"

using namespace mlir;

int main(int argc, char ** argv) {
  MLIRContext ctx;
  
  ctx.loadDialect<func::FuncDialect, arith::ArithDialect>();

  OpBuilder builder(&ctx);
  auto mod = builder.create<ModuleOp>(builder.getUnknownLoc());
  builder.setInsertionPointToEnd(mod.getBody());
  // auto src = parseSourceFile<ModuleOp>(argv[1], &ctx);
  
  auto i32 = builder.getI32Type();
  auto funcType = builder.getFunctionType({i32, i32}, {i32});
  auto func = builder.create<func::FuncOp>(builder.getUnknownLoc(), "test", funcType);
  auto entry = func.addEntryBlock();
  auto args = entry->getArguments();

  builder.setInsertionPointToEnd(entry);
  auto addi = builder.create<arith::AddIOp>(builder.getUnknownLoc(), args[0], args[1]);
  builder.create<func::ReturnOp>(builder.getUnknownLoc(), ValueRange({addi}));
  mod->print(llvm::outs());

  return 0;
}
