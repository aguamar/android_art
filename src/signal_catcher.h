/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ART_SRC_SIGNAL_CATCHER_H_
#define ART_SRC_SIGNAL_CATCHER_H_

#include <pthread.h>

namespace art {

class Runtime;
class Thread;

/*
 * A thread that catches signals and does something useful. For
 * example, when a SIGQUIT (Ctrl-\) arrives, we suspend and dump the
 * status of all threads.
 */
class SignalCatcher {
 public:
  SignalCatcher();
  ~SignalCatcher();

 private:
  static void* Run(void* arg);
  static void HandleSigQuit();
  static void HandleSigUsr1();

  static bool halt_;
  pthread_t thread_;
};

}  // namespace art

#endif  // ART_SRC_SIGNAL_CATCHER_H_
