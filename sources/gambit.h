//
// $Source$
// $Date$
// $Revision$
//
// DESCRIPTION:
// Declaration of main application class
//
// This file is part of Gambit
// Copyright (c) 2004, The Gambit Project
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//

#ifndef GAMBIT_H
#define GAMBIT_H

#include <libgambit/base/base.h>
#include <wx/docview.h>      // for wxFileHistory

class gbtGameFrame;

class gbtApplication : public wxApp {
private:
  wxFileHistory *m_fileHistory;
  gbtBlock<gbtGameFrame *> m_windows;

  bool OnInit(void);
  int OnExit(void);

public:
  gbtApplication(void);
  virtual ~gbtApplication();

  wxFileHistory *GetFileHistory(void) { return m_fileHistory; }

  int NumWindows(void) const  { return m_windows.Length(); }
  gbtGameFrame *GetWindow(int i) const { return m_windows[i]; }
  void AddWindow(gbtGameFrame *p_window) { m_windows.Append(p_window); }
  void RemoveWindow(gbtGameFrame *p_window)  
    { m_windows.Remove(m_windows.Find(p_window)); }
};

DECLARE_APP(gbtApplication)

#endif // GAMBIT_H
