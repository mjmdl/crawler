#ifndef CRAWLER__GAME_HPP
#define CRAWLER__GAME_HPP

#include <knave/knave.hpp>

namespace crawler
{
	class Game final : public knave::Application
	{
	public:
		Game(void) = default;
		virtual ~Game(void) override = default;

	protected:
		virtual void bootstrap(void) override;
		virtual void shutdown(void) override;
	};
} // crawler

#endif // CRAWLER__GAME_HPP
