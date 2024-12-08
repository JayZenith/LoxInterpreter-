#pragma once

#include <any>
#include <iosfwd>
#include <memory>
#include <vector>

#include "Expr/ExprVisitor.h"
#include "Stmt/StmtVisitor.h"

#include "Token.h"


class Expr;
class Stmt;



class Interpreter : public ExprVisitor<std::any>, public StmtVisitor<std::any> {
public:
public:
    Interpreter(std::ostream& out);
    ~Interpreter(); // for forward declaration of Environment
    void intepret(const std::vector<std::unique_ptr<Stmt>>& statements);

    //Environment& getGlobalsEnvironment();

    void execute(const Stmt& stmt);
    // void executeBlock(const std::vector<std::unique_ptr<Stmt>>& statements,
    //                   std::unique_ptr<Environment> env);
    std::any evaluate(const Expr& expr);

private:
    
    
    std::any visitLiteralExpr(const LiteralExpr& expr) override;
   

    std::any visitPrintStmt(const PrintStmt& stmt) override;

    // data
    // std::unique_ptr<Environment> globals;
    // Environment* globalEnvironment;
    // std::unique_ptr<Environment> environment; // current environment

    // class EnterEnviromentGuard {
    // public:
    //     EnterEnviromentGuard(Interpreter& i, std::unique_ptr<Environment> env);
    //     ~EnterEnviromentGuard();

    // private:
    //     Interpreter& i;
    //     std::unique_ptr<Environment> previous;
    // };

    std::ostream& out;
};

