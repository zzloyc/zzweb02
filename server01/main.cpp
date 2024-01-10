#include <fcgio.h>
#include <iostream>
#include <cstdlib>
int main() {
    // 初始化 FastCGI 环境
    FCGX_Request request;
    if (FCGX_InitRequest(&request, 0, 0) != 0) {
        std::cerr << "Failed to initialize FastCGI request." << std::endl;
        return 1;
    }
    while (FCGX_Accept_r(&request) == 0) {
        // 获取查询参数
        char *experiment_settings = FCGX_GetParam("ExperimentSettings", request.envp);
        // 输出 HTTP 头部
        FCGX_FPrintF(request.out,
            "Content-Type: text/plain\r\n"
            "\r\n");
        // 根据参数输出内容或执行相应操作
        if (experiment_settings) {
            std::cout << "Received ExperimentSettings: " << experiment_settings << std::endl;
            FCGX_FPrintF(request.out, "Received ExperimentSettings: %s\n", experiment_settings);
        } else {
            std::cerr << "No ExperimentSettings provided." << std::endl;
            FCGX_FPrintF(request.out, "No ExperimentSettings provided.\n");
        }
        // 清理环境变量等资源（对于 fcgio 库来说不是必须的，因为 FCGX_Accept_r 内部会处理）
    }
    // 对于 fcgio 库，不需要调用类似 FCGX_Free 的函数来释放资源
    return 0;
}