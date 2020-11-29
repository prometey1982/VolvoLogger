#pragma once

#include "J2534.hpp"
#include "LogParameters.hpp"

#include <mutex>
#include <condition_variable>
#include <thread>
#include <memory>

namespace j2534
{
	class J2534Channel;
}

namespace logger
{

	class Logger final
	{
	public:
		explicit Logger(j2534::J2534& j2534);
		~Logger();

		void start(const LogParameters& parameters, const std::wstring& savePath);
		void stop();

	private:
		std::unique_ptr<j2534::J2534Channel> openChannel(unsigned long ProtocolID, unsigned long Flags, unsigned long Baudrate);

	private:
		j2534::J2534& _j2534;
		LogParameters _parameters;
		std::thread _loggingThread;
		std::mutex _mutex;
		std::condition_variable _cond;
		bool _stopped;

		std::unique_ptr<j2534::J2534Channel> _channel1;
		std::unique_ptr<j2534::J2534Channel> _channel2;
		std::unique_ptr<j2534::J2534Channel> _channel3;
	};

} // namespace logger