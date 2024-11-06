#ifndef KNAVE__LOGGER_HPP
#define KNAVE__LOGGER_HPP

#include <memory>

#include <spdlog/spdlog.h>

#define KTRACE(...) Logger::engine->trace(__VA_ARGS__)
#define KDEBUG(...) Logger::engine->debug(__VA_ARGS__)
#define KINFO(...) Logger::engine->info(__VA_ARGS__)
#define KWARN(...) Logger::engine->warn(__VA_ARGS__)
#define KERROR(...) Logger::engine->error(__VA_ARGS__)
#define KFATAL(...) Logger::engine->critical(__VA_ARGS__)

#define LOG_TRACE(...) knave::Logger::game->trace(__VA_ARGS__)
#define LOG_DEBUG(...) knave::Logger::game->debug(__VA_ARGS__)
#define LOG_INFO(...) knave::Logger::game->info(__VA_ARGS__)
#define LOG_WARN(...) knave::Logger::game->warn(__VA_ARGS__)
#define LOG_ERROR(...) knave::Logger::game->error(__VA_ARGS__)
#define LOG_FATAL(...) knave::Logger::game->critical(__VA_ARGS__)

namespace knave
{
	class Logger
	{		
	public:
		static std::shared_ptr<spdlog::logger> engine;
		static std::shared_ptr<spdlog::logger> game;

		static void initialize(void);
	};
} // knave

#endif // KNAVE__LOGGER_HPP
