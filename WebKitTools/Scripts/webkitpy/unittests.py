#!/usr/bin/env python
# Copyright (c) 2009 Google Inc. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
#     * Redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above
# copyright notice, this list of conditions and the following disclaimer
# in the documentation and/or other materials provided with the
# distribution.
#     * Neither the name of Google Inc. nor the names of its
# contributors may be used to endorse or promote products derived from
# this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

# This module is imported by Scripts/test-webkitpy.

import sys

from webkitpy.common.checkout.changelog_unittest import *
from webkitpy.common.net.bugzilla_unittest import *
from webkitpy.common.net.buildbot_unittest import *
from webkitpy.tool.commands.download_unittest import *
from webkitpy.tool.commands.early_warning_system_unittest import *
from webkitpy.tool.commands.openbugs_unittest import OpenBugsTest
from webkitpy.tool.commands.upload_unittest import *
from webkitpy.tool.commands.queries_unittest import *
from webkitpy.tool.commands.queues_unittest import *
from webkitpy.tool.commands.sheriffbot_unittest import *
from webkitpy.common.checkout.commitinfo_unittest import *
from webkitpy.common.checkout.diff_parser_unittest import *
from webkitpy.common.config.committers_unittest import *
from webkitpy.common.net.credentials_unittest import *
from webkitpy.common.net.irc.unittests import *
from webkitpy.common.net.networktransaction_unittest import *
from webkitpy.executive_unittest import *
from webkitpy.grammar_unittest import *
from webkitpy.common.system.unittests import *  # for the webkitpy.init package
from webkitpy.layout_tests.port.mac_unittest import *
from webkitpy.python24.versioning_unittest import *
from webkitpy.tool.bot.queueengine_unittest import *
from webkitpy.tool.bot.patchcollection_unittest import *
from webkitpy.tool.multicommandtool_unittest import *
from webkitpy.tool.steps.steps_unittest import *
from webkitpy.tool.steps.closebugforlanddiff_unittest import *
from webkitpy.tool.steps.updatechangelogswithreview_unittests import *
from webkitpy.style.unittests import *  # for the webkitpy.style package
from webkitpy.user_unittest import *
from webkitpy.webkit_logging_unittest import *
from webkitpy.common.config.ports_unittest import *

# FIXME: This is a hack, but I'm tired of commenting out the test.
#        See https://bugs.webkit.org/show_bug.cgi?id=31818
if len(sys.argv) > 1 and sys.argv[1] == "--all":
    sys.argv.remove("--all")
    from webkitpy.common.checkout.scm_unittest import *
