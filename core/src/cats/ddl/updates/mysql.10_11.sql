-- Fix bad index on Media table
DROP INDEX inx8 ON Media;
CREATE UNIQUE INDEX inx8 ON Media (VolumeName(128));
ALTER TABLE File CHANGE FileId FileId BIGINT UNSIGNED NOT NULL AUTO_INCREMENT;
ALTER TABLE BaseFiles CHANGE FileId FileId BIGINT UNSIGNED NOT NULL;
ALTER TABLE Job ADD ReadBytes BIGINT UNSIGNED DEFAULT 0 AFTER JobBytes;
ALTER TABLE Media ADD ActionOnPurge TINYINT DEFAULT 0 AFTER Recycle;
ALTER TABLE Pool ADD ActionOnPurge TINYINT DEFAULT 0 AFTER Recycle;

DROP TABLE IF EXISTS JobHistory;

-- Create a table like Job for long term statistics
CREATE TABLE JobHisto (
   JobId INTEGER UNSIGNED NOT NULL,
   Job TINYBLOB NOT NULL,
   Name TINYBLOB NOT NULL,
   Type BINARY(1) NOT NULL,
   Level BINARY(1) NOT NULL,
   ClientId INTEGER DEFAULT 0,
   JobStatus BINARY(1) NOT NULL,
   SchedTime DATETIME DEFAULT 0,
   StartTime DATETIME DEFAULT 0,
   EndTime DATETIME DEFAULT 0,
   RealEndTime DATETIME DEFAULT 0,
   JobTDate BIGINT UNSIGNED DEFAULT 0,
   VolSessionId INTEGER UNSIGNED DEFAULT 0,
   VolSessionTime INTEGER UNSIGNED DEFAULT 0,
   JobFiles INTEGER UNSIGNED DEFAULT 0,
   JobBytes BIGINT UNSIGNED DEFAULT 0,
   ReadBytes BIGINT UNSIGNED DEFAULT 0,
   JobErrors INTEGER UNSIGNED DEFAULT 0,
   JobMissingFiles INTEGER UNSIGNED DEFAULT 0,
   PoolId INTEGER UNSIGNED DEFAULT 0,
   FileSetId INTEGER UNSIGNED DEFAULT 0,
   PriorJobId INTEGER UNSIGNED DEFAULT 0,
   PurgedFiles TINYINT DEFAULT 0,
   HasBase TINYINT DEFAULT 0,
   INDEX (StartTime)
);

UPDATE Version SET VersionId = 11;