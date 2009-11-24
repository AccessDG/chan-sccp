/*!
 * \file 	sccp_hint.h
 * \brief 	SCCP Hint Header
 * \author 	Marcello Ceschia <<marcello [at] ceschia.de>
 * \note 	This program is free software and may be modified and distributed under the terms of the GNU Public License.
 * \since 	2009-01-16
 */ 

#ifndef SCCP_HINT_H_
#define SCCP_HINT_H_

#include "asterisk.h"
#include "chan_sccp.h"

typedef enum {ASTERISK=0, INTERNAL=1} 		sccp_hinttype_t;
//#define SCCP_HINTSTATE_NOTINUSE		0
//#define SCCP_HINTSTATE_INUSE			1

typedef struct sccp_hint_SubscribingDevice sccp_hint_SubscribingDevice_t;

struct sccp_hint_SubscribingDevice {
        const sccp_device_t			* device;					/*!< SCCP Device */
        uint8_t					instance;					/*!< Instance as int */
        SCCP_LIST_ENTRY(sccp_hint_SubscribingDevice_t) list;					/*!< Hint Subscribing Device Linked List Entry */
};												/*!< Hint Subscribing Device Structure */

/**
 * we hold a mailbox event subscription in sccp_mailbox_subscription_t.
 *
 * Each line that holds a subscription for this mailbox is listed in
 */

typedef struct sccp_hint_list sccp_hint_list_t;

struct sccp_hint_list {
        ast_mutex_t 				lock;						/*!< Asterisk: Lock Me Up and Tie me Down */

        char 					exten[AST_MAX_EXTENSION];			/*!< Extension for Hint */
        char 					context[AST_MAX_CONTEXT];			/*!< Context for Hint */
        char 					hint_dialplan[256];				/*!< e.g. IAX2/station123 */

        sccp_channelState_t 			currentState;					/*!< Current Channel State */
        sccp_hinttype_t				hintType;					/*!< Type of Hint */

        struct {
                char 				callingPartyName[StationMaxNameSize];		/*!< Calling Party Name */
                char 				calledPartyName[StationMaxNameSize];		/*!< Called Party Name */
                char 				callingParty[StationMaxNameSize];		/*!< Calling Party ID */
                char 				calledParty[StationMaxNameSize];		/*!< Called Party ID */

                skinny_calltype_t 		calltype;					/*!< Type of Call */
        }callInfo;										/*!< Call Information Structure */


        union sccp_hint_type {

                struct {
                        char 			lineName[AST_MAX_EXTENSION];			/*!< LineName */
                } internal;									/*!< Hint Type Internal Structure */

                struct {
                        int			hintid;						/*!< Hint ID */
                        pthread_t 		notificationThread;				/*!< Notification Thread */
                } asterisk;									/*!< Hint Type Asterisk Structure */
        } type;											/*!< Hint Type Union */

        SCCP_LIST_HEAD(, sccp_hint_SubscribingDevice_t) subscribers;				/*!< Subscribers Linked List Entry */
        SCCP_LIST_ENTRY(sccp_hint_list_t) 	list;						/*!< Hint Linked List Entry */
};												/*!< Hint List Structure */


SCCP_LIST_HEAD(, sccp_hint_list_t) 		sccp_hint_subscriptions;

/**
 * \brief Hint State for Device
 * \param context Context as char
 * \param exten Extension as char
 * \param state State as Asterisk Extension State
 * \param data Asterisk Data
 * \return Status as int
 */
int sccp_hint_state(char *context, char* exten, enum ast_extension_states state, void *data);
void sccp_hint_lineStatusChanged(sccp_line_t *line, sccp_device_t *device, sccp_channel_t *channel, sccp_channelState_t previousState, sccp_channelState_t newState);
void sccp_hint_module_start(void);
void sccp_hint_module_stop(void);

#endif /* SCCP_HINT_H_ */
