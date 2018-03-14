#!/bin/sh
rm /var/palm/ls2/roles/pub/com.webos.rolegen.test.securityissues.json
rm /var/palm/ls2/roles/pub/com.webos.rolegen.test.securityissues2.json
rm /var/palm/ls2/roles/prv/com.webos.rolegen.test.securityissues.json
/usr/sbin/ls-control scan-volatile-dirs
