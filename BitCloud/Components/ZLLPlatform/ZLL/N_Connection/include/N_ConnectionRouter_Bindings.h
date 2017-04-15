#ifndef N_CONNECTIONROUTER_BINDINGS_H
#define N_CONNECTIONROUTER_BINDINGS_H

// implemented interface(s)
#define N_Connection_Subscribe N_ConnectionRouter_Subscribe_Impl
#define N_Connection_JoinNetwork N_ConnectionRouter_JoinNetwork_Impl
#define N_Connection_IsConnected N_ConnectionRouter_IsConnected_Impl
#define N_Connection_Reconnect N_ConnectionRouter_Reconnect_Impl
#define N_Connection_ReconnectUrgent N_ConnectionRouter_ReconnectUrgent_Impl
#define N_Connection_SetInterPanModeOn N_Connection_SetInterPanModeOn_Impl
#define N_Connection_SetInterPanModeOff N_Connection_SetInterPanModeOff_Impl
#define N_Connection_SetPollRate N_ConnectionRouter_SetPollRate_Impl
#define N_Connection_ForceNormalPolling N_ConnectionRouter_ForceNormalPolling_Impl
#define N_Connection_FindFreePan N_ConnectionRouter_FindFreePan_Impl
#define N_Connection_SendNetworkLeaveIndication N_ConnectionRouter_SendNetworkLeaveIndication_Impl

#define N_Connection_AssociateDiscovery N_Connection_AssociateDiscovery_Impl
#define N_Connection_AbortAssociateDiscovery N_Connection_AbortAssociateDiscovery_Impl
#define N_Connection_AssociateJoin N_Connection_AssociateJoin_Impl

#define N_Connection_UpdateNetwork N_Connection_UpdateNetwork_Impl
#define N_Connection_SetInterPanModeOn N_Connection_SetInterPanModeOn_Impl
#define N_Connection_SetInterPanModeOff N_Connection_SetInterPanModeOff_Impl
#define N_Connection_SetInitiatorInterPanModeOn N_Connection_SetInitiatorInterPanModeOn_Impl
#define N_Connection_SetInitiatorInterPanModeOff N_Connection_SetInitiatorInterPanModeOff_Impl
#define N_Connection_SetTargetInterPanModeOn N_Connection_SetTargetInterPanModeOn_Impl
#define N_Connection_SetTargetInterPanModeOff N_Connection_SetTargetInterPanModeOff_Impl
#define N_Connection_TargetIsInterpanModeOn N_Connection_TargetIsInterpanModeOn_Impl
#define N_Connection_SetTargetInterPanMacChannel N_Connection_SetTargetInterPanMacChannel_Impl

// used interfaces
#if defined(TESTHARNESS)

// N_AddressManager
#define N_AddressManager_AssignAddressRange N_AddressManager_Stub_AssignAddressRange

// N_Cmi
#  define N_Cmi_Subscribe N_Cmi_Stub_Subscribe
#  define N_Cmi_StartNetworking N_Cmi_Stub_StartNetworking
#  define N_Cmi_StartRouter N_Cmi_Stub_StartRouter
#  define N_Cmi_SetMacChannel N_Cmi_Stub_SetMacChannel
#  define N_Cmi_UpdateNetworkChannel N_Cmi_Stub_UpdateNetworkChannel
#  define N_Cmi_NetworkDiscovery N_Cmi_Stub_NetworkDiscovery
#  define N_Cmi_SendLinkStatus N_Cmi_Stub_SendLinkStatus
#  define N_Cmi_Join N_Cmi_Stub_Join
#  define N_Cmi_ResetNetworkSettings N_Cmi_Stub_ResetNetworkSettings
#  define N_Cmi_GetNetworkParams N_Cmi_Stub_GetNetworkParams
#  define N_Cmi_GetParentInfo N_Cmi_Stub_GetParentInfo
#  define N_Cmi_SwitchNetworkKey N_Cmi_Stub_SwitchNetworkKey
#  define N_Cmi_GetTotalTransmissions N_Cmi_Stub_GetTotalTransmissions
#  define N_Cmi_EnergyDetectScan N_Cmi_Stub_EnergyDetectScan
#  define N_Cmi_SendLeaveIndication N_Cmi_Stub_SendLeaveIndication
#  define N_Cmi_ProcessLeaveIndication N_Cmi_Stub_ProcessLeaveIndication
#  define N_Cmi_SendUpdateDevice N_Cmi_Stub_SendUpdateDevice
#  define N_Cmi_UseNwkMulticast N_Cmi_UseNwkMulticast_Impl
#  define N_Cmi_InitMacLayer N_Cmi_InitMacLayer_Impl

// N_DeviceInfo
#  define N_DeviceInfo_IsFactoryNew N_DeviceInfo_Stub_IsFactoryNew
#  define N_DeviceInfo_GetNetworkChannel N_DeviceInfo_Stub_GetNetworkChannel
#  define N_DeviceInfo_GetChannelForIndex N_DeviceInfo_Stub_GetChannelForIndex
#  define N_DeviceInfo_IsChannelInMask N_DeviceInfo_Stub_IsChannelInMask
#  define N_DeviceInfo_GetNrChannelsInChannelMask N_DeviceInfo_Stub_GetNrChannelsInChannelMask
#  define N_DeviceInfo_GetPrimaryChannelMask N_DeviceInfo_Stub_GetPrimaryChannelMask
#  define N_DeviceInfo_GetSecondaryChannelMask N_DeviceInfo_Stub_GetSecondaryChannelMask
#  define N_DeviceInfo_GetNetworkUpdateId N_DeviceInfo_Stub_GetNetworkUpdateId
#  define N_DeviceInfo_GetNetworkExtendedPanId N_DeviceInfo_Stub_GetNetworkExtendedPanId
#  define N_DeviceInfo_Subscribe N_DeviceInfo_Stub_Subscribe
#  define N_DeviceInfo_SetNetworkChannel N_DeviceInfo_Stub_SetNetworkChannel
#  define N_DeviceInfo_SetNetworkUpdateId N_DeviceInfo_Stub_SetNetworkUpdateId
#  define N_DeviceInfo_SetNetworkExtendedPanId N_DeviceInfo_Stub_SetNetworkExtendedPanId
#  define N_DeviceInfo_SetNetworkPanId N_DeviceInfo_Stub_SetNetworkPanId
#  define N_DeviceInfo_SetNetworkAddress N_DeviceInfo_Stub_SetNetworkAddress
#  define N_DeviceInfo_SetParentIEEEAddress N_DeviceInfo_Stub_SetParentIEEEAddress
#  define N_DeviceInfo_SetParentNetworkAddress N_DeviceInfo_Stub_SetParentNetworkAddress
#  define N_DeviceInfo_SetFactoryNew N_DeviceInfo_Stub_SetFactoryNew
#  define N_DeviceInfo_GetTrustCenterMode N_DeviceInfo_Stub_GetTrustCenterMode

// N_Security
#  define N_Security_GetRandomData N_Security_Stub_GetRandomData
#  define N_Security_GenerateNewNetworkKey N_Security_Stub_GenerateNewNetworkKey

// N_Timer uses the actual implementation
#  define N_Timer_Start16 N_Timer_Start16_Impl
#  define N_Timer_Stop N_Timer_Stop_Impl

// N_Zdp
#  define N_Zdp_SendDeviceAnnounce N_Zdp_Stub_SendDeviceAnnounce
#  define N_Zdp_ServerSubscribe N_Zdp_Stub_ServerSubscribe
#  define N_Zdp_GetSourceAddress N_Zdp_Stub_GetSourceAddress
#  define N_Zdp_SendMgmtNwkUpdateNotify N_Zdp_Stub_SendMgmtNwkUpdateNotify

// N_Util
#  define N_Util_Random N_Util_Stub_Random

#else

// N_AddressManager
#define N_AddressManager_AssignAddressRange N_AddressManager_AssignAddressRange_Impl

// N_Cmi
#  define N_Cmi_Subscribe N_Cmi_Subscribe_Impl
#  define N_Cmi_StartNetworking N_Cmi_StartNetworking_Impl
#  define N_Cmi_StartRouter N_Cmi_StartRouter_Impl
#  define N_Cmi_SetMacChannel N_Cmi_SetMacChannel_Impl
#  define N_Cmi_UpdateNetworkChannel N_Cmi_UpdateNetworkChannel_Impl
#  define N_Cmi_NetworkDiscovery N_Cmi_NetworkDiscovery_Impl
#  define N_Cmi_SendLinkStatus N_Cmi_SendLinkStatus_Impl
#  define N_Cmi_Join N_Cmi_Join_Impl
#  define N_Cmi_ResetNetworkSettings N_Cmi_ResetNetworkSettings_Impl
#  define N_Cmi_GetNetworkParams N_Cmi_GetNetworkParams_Impl
#  define N_Cmi_GetParentInfo N_Cmi_GetParentInfo_Impl
#  define N_Cmi_SwitchNetworkKey N_Cmi_SwitchNetworkKey_Impl
#  define N_Cmi_GetTotalTransmissions N_Cmi_GetTotalTransmissions_Impl
#  define N_Cmi_EnergyDetectScan N_Cmi_EnergyDetectScan_Impl
#  define N_Cmi_SendLeaveIndication N_Cmi_SendLeaveIndication_Impl
#  define N_Cmi_ProcessLeaveIndication N_Cmi_ProcessLeaveIndication_Impl
#  define N_Cmi_SendUpdateDevice N_Cmi_SendUpdateDevice_Impl
#  define N_Cmi_SetZllLinkKeyAsPrimary N_Cmi_SetZllLinkKeyAsPrimary_Impl
#  define N_Cmi_UseNwkMulticast N_Cmi_UseNwkMulticast_Impl
#  define N_Cmi_InitMacLayer N_Cmi_InitMacLayer_Impl

// N_DeviceInfo
#  define N_DeviceInfo_IsFactoryNew N_DeviceInfo_IsFactoryNew_Impl
#  define N_DeviceInfo_GetNetworkChannel N_DeviceInfo_GetNetworkChannel_Impl
#  define N_DeviceInfo_GetChannelForIndex N_DeviceInfo_GetChannelForIndex_Impl
#  define N_DeviceInfo_IsChannelInMask N_DeviceInfo_IsChannelInMask_Impl
#  define N_DeviceInfo_GetNrChannelsInChannelMask N_DeviceInfo_GetNrChannelsInChannelMask_Impl
#  define N_DeviceInfo_GetPrimaryChannelMask N_DeviceInfo_GetPrimaryChannelMask_Impl
#  define N_DeviceInfo_GetSecondaryChannelMask N_DeviceInfo_GetSecondaryChannelMask_Impl
#  define N_DeviceInfo_GetNetworkUpdateId N_DeviceInfo_GetNetworkUpdateId_Impl
#  define N_DeviceInfo_GetNetworkExtendedPanId N_DeviceInfo_GetNetworkExtendedPanId_Impl
#  define N_DeviceInfo_Subscribe N_DeviceInfo_Subscribe_Impl
#  define N_DeviceInfo_SetNetworkChannel N_DeviceInfo_SetNetworkChannel_Impl
#  define N_DeviceInfo_SetNetworkUpdateId N_DeviceInfo_SetNetworkUpdateId_Impl
#  define N_DeviceInfo_SetNetworkExtendedPanId N_DeviceInfo_SetNetworkExtendedPanId_Impl
#  define N_DeviceInfo_SetNetworkPanId N_DeviceInfo_SetNetworkPanId_Impl
#  define N_DeviceInfo_SetNetworkAddress N_DeviceInfo_SetNetworkAddress_Impl
#  define N_DeviceInfo_SetParentIEEEAddress N_DeviceInfo_SetParentIEEEAddress_Impl
#  define N_DeviceInfo_SetParentNetworkAddress N_DeviceInfo_SetParentNetworkAddress_Impl
#  define N_DeviceInfo_SetFactoryNew N_DeviceInfo_SetFactoryNew_Impl
#  define N_DeviceInfo_GetTrustCenterMode N_DeviceInfo_GetTrustCenterMode_Impl
#  define N_DeviceInfo_IsEndDevice N_DeviceInfo_IsEndDevice_Impl

// N_Security
#  define N_Security_GetRandomData N_Security_GetRandomData_Impl
#  define N_Security_GenerateNewNetworkKey N_Security_GenerateNewNetworkKey_Impl

// N_Timer
#  define N_Timer_Start16 N_Timer_Start16_Impl
#  define N_Timer_Stop N_Timer_Stop_Impl

// N_Zdp
#  define N_Zdp_SendDeviceAnnounce N_Zdp_SendDeviceAnnounce_Impl
#  define N_Zdp_ServerSubscribe N_Zdp_ServerSubscribe_Impl
#  define N_Zdp_GetSourceAddress N_Zdp_GetSourceAddress_Impl
#  define N_Zdp_SendMgmtNwkUpdateNotify N_Zdp_SendMgmtNwkUpdateNotify_Impl
#  define N_Zdp_SendMgmtNwkUpdateReq N_Zdp_SendMgmtNwkUpdateReq_Impl
// N_Util
# define N_Util_Random N_Util_Random_Impl

// N_LinkTarget
#define N_LinkTarget_SetTargetType N_LinkTarget_SetTargetType_Impl

// N_Radio_Internal
#define N_Radio_SetChannel N_Radio_SetChannel_Impl

#endif

#endif  /*N_CONNECTIONROUTER_BINDINGS_H*/
