/* 
 * File:   UtilConfigAccess.h
 * Author: Gavin Chan
 *
 * Created on February 14, 2016, 12:25 AM
 */

#ifndef CUTILCONFIGACCESS_H
#define	CUTILCONFIGACCESS_H

#include <unordered_map>

class CUtilConfigAccess {
public:
	static std::string PATH;
	
	static CUtilConfigAccess& Instance()
	{
		static CUtilConfigAccess instance(PATH);
		return instance;
	}
	
	/**
	 * Read config file from path
	 * @param path Absolute path
	 * @return true if success
	 */
	bool ReadFromPath(std::string path);

	/**
	 * Get value from key
	 * @param key Key string
	 * @param value Returned value
	 * @return true if found
	 */
	bool GetValue(std::string key, std::string& value);

	/**
	 * Get value from key. If value is failed to get, assertion
	 * will be failed. It is unsafe version of another GetValue
	 * function  
	 * @param key Key string
	 * @return Value
	 */
	std::string GetValue(std::string key);
	
	/**
	 * Constructor 
	 */
    CUtilConfigAccess();

	/**
	 * Constructor with config path 
	 * @param path Config path
	 */
    CUtilConfigAccess(std::string path);

	/**
	 * Copy constructor
	 * @param orig Copy object
	 */
    CUtilConfigAccess(const CUtilConfigAccess& orig);

	/**
	 * Destructor
	 */
    virtual ~CUtilConfigAccess();

private:
	std::unordered_map<std::string,std::string> _map;
};

#endif	/* CUTILCONFIGACCESS_H */

