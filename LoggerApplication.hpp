#pragma once

#include <memory>
#include <string>

namespace j2534 {
class J2534;
}

namespace logger {
class Logger;
class LogParameters;

class LoggerApplication final {
public:
  static LoggerApplication &instance();

  void start(unsigned long baudrate, std::unique_ptr<j2534::J2534> &&j2534,
             const LogParameters &params, const std::string &outputPath);
  void stop();

  bool isStarted() const;

private:
  LoggerApplication();
  ~LoggerApplication();

  std::unique_ptr<j2534::J2534> _j2534;
  std::unique_ptr<Logger> _logger;
};

} // namespace logger