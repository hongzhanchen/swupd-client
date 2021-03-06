#ifndef __CONFIG_LOADER__
#define __CONFIG_LOADER__

/**
 * @file
 * @brief Load options from a configuration file
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

/**
 * @brief Type of function that sets options for a section based on parsed values
 */
typedef bool (*parse_opt_fn_t)(int opt, char *optarg);

/**
 * @brief Data structed used by config_loader_set_opt()
 */
struct config_loader_data {
	/** @brief Swupd subcommand being executed */
	char *command;
	/** @brief Array with available opts. */
	const struct option *available_opts;
	/** @brief Function to parse global options */
	parse_opt_fn_t parse_global_opt;
	/** @brief Function to parse subcommand specific options */
	parse_opt_fn_t parse_command_opt;
};

/**
 * Process parser config file and call apropriate function in struct config_loader_data
 * informed on data
 */
bool config_loader_set_opt(char *section, char *key, char *value, void *data);

#ifdef __cplusplus
}
#endif
#endif
