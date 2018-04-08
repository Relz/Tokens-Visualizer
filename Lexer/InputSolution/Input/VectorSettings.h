#ifndef PROJECT_VECTORSETTINGS_H
#define PROJECT_VECTORSETTINGS_H

#include <unordered_map>
#include "BaseSettings.h"
#include "Constant.h"

template <typename T> class VectorSettingsBuilder;

template <typename T>
class VectorSettings
{
	friend class VectorSettingsBuilder<T>;
public:
	VectorSettings() = default;

	BaseSettings const& GetBaseSettings() const
	{
		return m_baseSettings;
	}

	char GetTrueChar() const
	{
		return m_trueChar;
	}

	std::unordered_map<char, T> GetRules() const
	{
		return m_rules;
	}

private:
	BaseSettings m_baseSettings;
	char m_trueChar = NOT_A_CHARACTER;
	std::unordered_map<char, T> m_rules;
};

template<typename T = char>
class VectorSettingsBuilder
{
public:
	VectorSettingsBuilder() = default;

	VectorSettingsBuilder & SetTrueChar(char trueChar)
	{
		m_vectorSettings.m_trueChar = trueChar;
		return *this;
	}

	VectorSettingsBuilder & SetRules(std::unordered_map<char, T> rules)
	{
		m_vectorSettings.m_rules = std::move(rules);
		return *this;
	}

	VectorSettings<T> const& Build(BaseSettings const& baseSettings = BaseSettings())
	{
		m_vectorSettings.m_baseSettings = baseSettings;
		return m_vectorSettings;
	}

private:
	VectorSettings<T> m_vectorSettings;
};

#endif //PROJECT_VECTORSETTINGS_H
