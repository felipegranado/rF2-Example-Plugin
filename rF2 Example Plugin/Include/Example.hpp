//###########################################################################
//#                                                                         #
//# Module: Internals Example Header File                                   #
//#                                                                         #
//# Description: Declarations for the Internals Example Plugin              #
//#                                                                         #
//#                                                                         #
//# This source code module, and all information, data, and algorithms      #
//# associated with it, are part of CUBE technology (tm).                   #
//#                 PROPRIETARY AND CONFIDENTIAL                            #
//# Copyright (c) 2017 Studio 397 B.V.  All rights reserved.               #
//#                                                                         #
//#                                                                         #
//# Change history:                                                         #
//#   tag.2005.11.30: created                                               #
//#                                                                         #
//###########################################################################

#ifndef _INTERNALS_EXAMPLE_H
#define _INTERNALS_EXAMPLE_H

#include "InternalsPlugin.hpp"


// This is used for the app to use the plugin for its intended purpose
class ExampleInternalsPlugin : public InternalsPluginV01  // REMINDER: exported function GetPluginVersion() should return 1 if you are deriving from this InternalsPluginV01, 2 for InternalsPluginV02, etc.
{

 public:

  // Constructor/destructor
  ExampleInternalsPlugin() {}
  ~ExampleInternalsPlugin() {}

  // These are the functions derived from base class InternalsPlugin
  // that can be implemented.
  void Startup( long version );  // game startup
  void Shutdown();               // game shutdown

  void EnterRealtime();          // entering realtime
  void ExitRealtime();           // exiting realtime

  void StartSession();           // session has started
  void EndSession();             // session has ended

  // GAME OUTPUT
  long WantsTelemetryUpdates() { return( 1 ); } // CHANGE TO 1 TO ENABLE TELEMETRY EXAMPLE!
  void UpdateTelemetry( const TelemInfoV01 &info );

  bool WantsGraphicsUpdates() { return( false ); } // CHANGE TO TRUE TO ENABLE GRAPHICS EXAMPLE!
  void UpdateGraphics( const GraphicsInfoV01 &info );

  // GAME INPUT
  bool HasHardwareInputs() { return( false ); } // CHANGE TO TRUE TO ENABLE HARDWARE EXAMPLE!
  void UpdateHardware( const double fDT ) { mET += fDT; } // update the hardware with the time between frames
  void EnableHardware() { mEnabled = true; }             // message from game to enable hardware
  void DisableHardware() { mEnabled = false; }           // message from game to disable hardware

  // See if the plugin wants to take over a hardware control.  If the plugin takes over the
  // control, this method returns true and sets the value of the double pointed to by the
  // second arg.  Otherwise, it returns false and leaves the double unmodified.
  bool CheckHWControl( const char * const controlName, double &fRetVal );

  bool ForceFeedback( double &forceValue );  // SEE FUNCTION BODY TO ENABLE FORCE EXAMPLE

  // SCORING OUTPUT
  bool WantsScoringUpdates() { return( false ); } // CHANGE TO TRUE TO ENABLE SCORING EXAMPLE!
  void UpdateScoring( const ScoringInfoV01 &info );

  // COMMENTARY INPUT
  bool RequestCommentary( CommentaryRequestInfoV01 &info );  // SEE FUNCTION BODY TO ENABLE COMMENTARY EXAMPLE

 private:

  void WriteToAllExampleOutputFiles( const char * const openStr, const char * const msg );
  double mET;  // needed for the hardware example
  bool mEnabled; // needed for the hardware example
};


#endif // _INTERNALS_EXAMPLE_H

