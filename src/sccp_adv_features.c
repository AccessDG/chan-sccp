/*!
 * \file        sccp_adv_features.c
 * \brief       SCCP Advanced Features Class
 * \author      Sergio Chersovani <mlists [at] c-net.it>
 * \author      Federico Santulli <fsantulli [at] users.sourceforge.net>
 * \note        Reworked, but based on chan_sccp code.
 *              The original chan_sccp driver that was made by Zozo which itself was derived from the chan_skinny driver.
 *              Modified by Jan Czmok and Julien Goodwin
 * \note        This program is free software and may be modified and distributed under the terms of the GNU Public License. 
 *              See the LICENSE file at the top of the source tree.
 * 
 * $Date$
 * $Revision$
 */
#include <config.h>
#include "common.h"
#include "sccp_adv_features.h"

SCCP_FILE_VERSION(__FILE__, "$Revision$");

/*!
 * \brief Dummy Procedure 1
 */
void dummyproc1(void)
{
	/* this is a dummy proc */
	if (0) {
		dummyproc2();
	}
}

/*!
 * \brief Dummy Procedure 2
 */
void dummyproc2(void)
{
	/* this is a dummy proc */
	if (0) {
		dummyproc1();
	}
}

// kate: indent-width 8; replace-tabs off; indent-mode cstyle; auto-insert-doxygen on; line-numbers on; tab-indents on; keep-extra-spaces off; auto-brackets off;
