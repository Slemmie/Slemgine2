#pragma once

namespace slg {
	
	class LOG {
		
	public:
		
		template <typename... A> static void trace(const char message[], const A&... param_args);
		template <typename... A> static void trace(const A&... param_args);
		
	private:
		
		static std::vector <Token> m_interpret_msg(const std::string& message);
		
	private:
		
		struct Arg {
			
			std::string data;
			
			template <typename A> Arg(const A& _arg);
			
		};
		
		struct Format {
			
			
			
		};
		
		struct Token {
			
			uint64_t arg_index;
			
			Format format;
			
			Token(const std::string& _format_str);
			
		};
		
	};
	
	template <typename... A> static void LOG::trace(const char message[], const A&... param_args) {
		std::vector <LOG::Arg> args;
	}
	
	template <typename... A> static void LOG::trace(const A&... param_args) {
		std::vector <LOG::Arg> args;
	}
	
	static std::vector <Token> LOG::m_interpret_msg(const std::string& message) {
		
	}
	
	template <typename A> LOG::Arg::Arg(const A& _arg) {
		std::stringstream stream;
		stream << _arg;
		data = stream.str();
	}
	
	LOG::Token::Token(const std::string& _format_str) {
		
	}
	
} /// namespace slg
