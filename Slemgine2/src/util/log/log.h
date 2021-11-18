#pragma once

#include <vector>
#include <string>
#include <sstream>

namespace slg {
	
	class LOG {
		
	public:
		
		// format information for entire message
		struct Format {
			
			// codes (0 if not provided)
			uint8_t fg_r, fg_g, fg_b;
			uint8_t bg_r, bg_g, bg_b;
			uint8_t bold_faint;
			uint8_t crossed;
			uint8_t underlined;
			uint8_t overlined;
			
			// stringafied codes
			std::string str;
			
			Format(const char _format[]);
			
		};
		
		// trace - use explicit format
		template <typename... A> static void trace(const Format& format, const char message[], const A&... param_args);
		template <typename... A> static void trace(const Format& format, const A&... param_args);
		
		// trace - use implicit format
		template <typename... A> static void trace(const char message[], const A&... param_args);
		template <typename... A> static void trace(const A&... param_args);
		
	private:
		
		// produce list of formatted arguments from raw, variable amount, types
		template <typename... A> static std::vector <Arg> m_interpret_args(const A&... param_args);
		
		// produce list of tokens from message and list of formatted arguments
		static std::vector <Token> m_interpret_msg(const std::string& message, const std::vector <Arg>& args);
		
	private:
		
		// string form of any data type argument passed to log call
		struct Arg {
			
			std::string data_raw;
			std::string data_formatted;
			
			template <typename A> Arg(const A& _arg);
			
		};
		
		// individual parts (e.g. plain text bits or argument substition bits) of entire main message
		struct Token {
			
			std::string data;
			
			// plain text, use general format
			Token(const std::string& _str, const Format& _format);
			// argument substitution, use format given in '_str'
			Token(const std::string& _str, const std::vector <Arg>& _args);
			
		};
		
	};
	
} /// namespace slg
