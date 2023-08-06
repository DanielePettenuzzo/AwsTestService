#include <cpp-template/cpp_template.hpp>
#include <restinio/all.hpp>

int main(int /* argc */, char** /* argv */)
{
  std::cout << "Hello, World!" << std::endl;
  try {
    restinio::run(
        restinio::on_this_thread().port(8080).address("localhost").request_handler([](auto req) {
          std::cout << "Request..." << std::endl;
          return req->create_response().set_body("Hello, World!").done();
        }));
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}
